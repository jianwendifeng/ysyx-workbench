package rv64

import chisel3._
import chisel3.util._

class PC extends Module {
  val io = IO(new Bundle {
    val pcIN = Input(UInt(32.W))
    val idu_inst = Input(UInt(32.W))
    val pcOut = Output(UInt(32.W))
  })

  val instrMem = Mem(1024, UInt(32.W)) //设指令存储器有 1024 个地址，每个地址对应一个 32 位指令
  io.idu_inst = instrMem(pcIN)  //读取指令

  // 创建一个 32 位的 PC 寄存器，并初始化为 0
  val pcReg = RegInit(0.U(32.W))
  pcReg := io.pcIN + 4
  // 输出当前的 PC 值
  io.pcOut := pcReg
}

