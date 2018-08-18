var io = require('socket.io')();
console.log('Starting B');

var message;

io.on('connection', function(socket){
  io.on('broadcast',function(_message){
    message = _message;
  })
});

console.log(message);
