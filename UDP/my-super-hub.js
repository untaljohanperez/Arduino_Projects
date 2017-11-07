var clientFromConnectionString = require('azure-iot-device-mqtt').clientFromConnectionString;
var Message = require('azure-iot-device').Message;

var connectionString = 'HostName=MySuperHub.azure-devices.net;DeviceId=COSensor;SharedAccessKey=sQ/MyV3sXz7B9QPlEYFip9VJa9pRr0s1Lt2W2wtzn70=';

var client = clientFromConnectionString(connectionString);

function printResultFor(op) {
  return function printResult(err, res) {
    if (err) console.log(op + ' error: ' + err.toString());
    if (res) console.log(op + ' status: ' + res.constructor.name);
  };
}

var isConnected = false;

var connectCallback = function (err) {
  if (err) { 
    console.log('Could not connect: ' + err);
  } else {
    console.log('Client connected');
	isConnected = true;
  }
}

module.exports = {
  openConnection: function() {
    client.open(connectCallback); 
  },
  sendData: function(data) {
	if (!isConnected) {
		console.log('Could not connect with IOT hub');
		return;
	}
    var message = new Message(data);
    console.log("Sending message: " + message.getData());
    client.sendEvent(message, printResultFor('send'));	
  }
}