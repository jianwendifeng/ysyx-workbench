package rv64

import chisel3._
import chisel3.util._

class ctr_signalsIO extends Bundle {
    val alu_sel = Output(UInt(4.W))
    val a_sel = Output(UInt(1.W))
    val b_sel = Output(UInt(1.W))
    val imm_sel = Output(UInt(3.W))
    val rf_en = Output(Bool())
    val mem_en = Output(Bool())
    val wb_en = Output(Bool())
}

class IFUIO(Xlen: Int) extends Bundle {
  val pc_in = Input(UInt(Xlen.W))
  val inst_in = Input(UInt(Xlen.W))
  val inst = Output(UInt(Xlen.W))
  val pc_out = Output(UInt(Xlen.W))   //pc递增在core模块实现
}
class IDUIO(Xlen: Int) extends Bundle{
    val inst = Input(UInt(32.W))
    val pc = Input(UInt(32.W))
    val rs1_data = Input(UInt(Xlen.W))
    val rs2_data = Input(UInt(Xlen.W))
    val rs1 = Output(UInt(5.W))
    val rs2 = Output(UInt(5.W))
    val rd = Output(UInt(5.W))
    val a = Output(UInt(Xlen.W))
    val b = Output(UInt(Xlen.W))
    val ctr_signals_out = new ctr_signalsIO
}


class DecodeIO(Xlen: Int) extends Bundle
{
    val inst = Input(UInt(Xlen.W))
    val ctr_signals = new ctr_signalsIO
   
}

class EXUIO(Xlen: Int) extends Bundle {
    val a = Input(UInt(Xlen.W))
    val b = Input(UInt(Xlen.W))
    val ctr_signals_in = Flipped(new ctr_signalsIO)
    val ctr_signals_out = new ctr_signalsIO
    val rd_in = Input(UInt(5.W))
    val rd_out = Output(UInt(5.W))
    val data = Output(UInt(Xlen.W))
}

class ALUIO(Xlen: Int) extends Bundle {
    val a = Input(UInt(Xlen.W))
    val b = Input(UInt(Xlen.W))
    
    val result = Output(UInt(Xlen.W))
    val ctr_signals_in = Flipped(new ctr_signalsIO)
}


class MEMIO(Xlen: Int) extends Bundle {
    val rd_in = Input(UInt(5.W))
    val result_in = Input(UInt(Xlen.W))
    val ctr_signals_in = Flipped(new ctr_signalsIO)
    val ctr_signals_out = new ctr_signalsIO
    // val wen_out = Output(Bool())
    val rd_out = Output(UInt(5.W))
    val result_out = Output(UInt(Xlen.W))
}

class WBUIO(Xlen: Int) extends Bundle {
    val ctr_signals_in = Flipped(new ctr_signalsIO)
    val wen = Output(Bool())
    val waddr_in = Input(UInt(5.W))
    val wdata_in = Input(UInt(Xlen.W))
    val waddr_out = Output(UInt(5.W))
    val wdata_out = Output(UInt(Xlen.W))
}

class RegFileIO(xlen: Int) extends Bundle {
    val raddr1 = Input(UInt(5.W))
    val raddr2 = Input(UInt(5.W))
    val rdata1 = Output(UInt(xlen.W))
    val rdata2 = Output(UInt(xlen.W))
    val ren = Input(Bool())
    val wen = Input(Bool())
    val waddr = Input(UInt(5.W))
    val wdata = Input(UInt(xlen.W))
}

class ImemIO extends Bundle {
    val addr = Input(UInt(32.W))
    val inst = Output(UInt(32.W))
}
