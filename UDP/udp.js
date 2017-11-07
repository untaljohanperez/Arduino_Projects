var mySuperHub = require("./my-super-hub.js");

var PORT = process.argv[2] || 33333;
var HOST =  process.argv[3] ||'172.20.10.4';

var dgram = require('dgram');
var server = dgram.createSocket('udp4');

server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
	mySuperHub.openConnection();
});

server.on('message', function (message, remote) {
    console.log(remote.address + ':' + remote.port +' - ' + message);	
	var data = JSON.stringify({ deviceId: 'COSensor', co: message });
	mySuperHub.sendData(data);
});

server.bind(PORT, HOST);
