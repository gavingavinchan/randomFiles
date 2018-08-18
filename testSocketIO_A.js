var io = require('socket.io')();
console.log('Starting A');
var socketB = require('./testSocketIO_B.js');

io.on('connection', function(client){});
io.listen(3000);

io.on('connection', function(socket){
  socket.emit('request', 'Kim Jong Un'); // emit an event to the socket
  io.emit('broadcast', 'Donald Trump'); // emit an event to all connected sockets
  socket.on('reply', function(){
    console.log('A got the message')
  }); // listen to the event
});
