// package rv64

// import chisel3._
// import chisel3.util

// class Message extends Bundle{
//     val inst = Output(UInt(32.W))
//     val pc = Output(UInt(64.W))
//     //指令类型
// }

// class IFU extends Module{
//     val io = IO(new Bundle { val out = Decoupled(new Message) })
//     //
// }

// class IDU extends Module{
//     val io = IO(new Bundle { val in = Filpped(Decoupled(new Message)) })
//     //
// }