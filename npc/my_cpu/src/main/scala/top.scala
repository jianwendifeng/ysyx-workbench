package top

import chisel3._
import chisel3.util._
import chisel3.stage._

import rv64._

class top extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val pc = Output(UInt(32.W))
    val exit = Output(UInt(32.W))
    val idu_op = Output(UInt(32.W))
    val exu_data = Output(UInt(32.W))
    val exu_data1 = Output(UInt(32.W))
    val exu_data2 = Output(UInt(32.W))
    val mem_data = Output(UInt(32.W))
    val wbu_data = Output(UInt(32.W))
  })

  val core = Module(new Core())
  io.pc := core.io.pc
  io.inst <> core.io.inst
  io.exit := core.io.exit
  io.idu_op := core.io.idu_op
  io.exu_data := core.io.exu_data
  io.exu_data1 := core.io.exu_data1
  io.exu_data2 := core.io.exu_data2
  io.mem_data := core.io.mem_data
  io.wbu_data := core.io.wbu_data
}

object topMain extends App{
  (new ChiselStage).emitVerilog(new top(), args)
}


// class top extends Module {
//    val io = IO(new Bundle {
//     val input = Input(UInt32.W)
//     val output = Output(UInt32.W)
//    })

//    val ifstage = Module(new IFU(xlen = 64))
//    val idstage = Module(new IDU(xlen = 64))
//    val exstage = Module(new EXU(xlen = 64))
//    val memstage = Module(new Memory(xlen = 64))
//    val wbstage = Module(new WB(xlen = 64))

//    val pc = RegInit(0x1000)
//    val next_pc = Mux(true,pc + 4) //Mux 来取代mux，作为pc的选择一部分

//    ifstate.io.input <> io.input
//    ifstage.io.output <> idstage.io.input
//    idstage.io.output <> exstage.io.input
//    memstage.io.output <> wbstage.io.input
   
// }

// object topMain extends APP {
//   (new ChiselStage).emitVerilog(new top, args)
// }