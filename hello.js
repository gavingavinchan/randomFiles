// Server
var io1 = require('socket.io').listen(8321);

io1.on('connection', function(socket1) {


  socket1.use((packet, next) => {
    io1.emit(packet[0], packet[1]);
    return next();
  });

  socket1.use((packet, next) => {
    console.log(new Date() + '\t' + packet[0] + '\t' + packet[1]);
    return next();
  });

  console.log('connection');
  socket1.on('bar', function(msg1) {
    console.log('s' + msg1);
    //io1.emit('sev', 'message from server!!!');
  });
});

// Mirror


// Client
var io2 = require('socket.io-client');
var socket2 = io2.connect('http://localhost:8321');

var msg2 = "hello from 2";
socket2.on('sev', function(msg){
  // console.log('server' + msg);
})

socket2.emit('status', msg2);

var socket3 = io2.connect('http://localhost:8321');

var msg3 = "hello from 3";
socket3.on('status', function(msg){
  console.log('bar-3' + msg);
})

socket3.emit('thrust', msg3);
