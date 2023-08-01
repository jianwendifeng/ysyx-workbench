package rv64

import chisel3._
import chisel3.util._

class IFUIO(Xlen: Int) extends Bundle {
  val pc_in = Input(UInt(Xlen.W))
  val inst_in = Input(UInt(Xlen.W))
  val inst = Output(UInt(Xlen.W))
  //val pc_out = Output(UInt(xlen.W))   //pc递增在core模块实现
}

class IFU(Xlen: Int) extends Module {
  val io = IO(new IFUIO(Xlen))


//   val instrMem = Mem(1024, UInt(32.W)) //设指令存储器有 1024 个地址，每个地址对应一个 32 位指令

  // 创建一个 32 位的 指令寄存器，并初始化为 0
  val inst_reg = RegInit(0.U(Xlen.W))
  inst_reg := io.inst_in

//   inst_reg := instrMem(io.pc_in)  //读取指令

  io.inst := inst_reg
}


