package rv64

import chisel3._
import chisel3.util._

class WBUIO(Xlen: Int) extends Bundle {
    val wen = Input(Bool())
    val rd = Input(UInt(5.W))
    val data = Input(UInt(Xlen.W))
}

class WBU(Xlen: Int) extends Module {
    val io = IO(new WBUIO(Xlen))
    val rd = RegInit(0.U(5.W))
    val data = RegInit(0.U(Xlen.W))
    val en = RegInit(false.B)

    val regFileInst = Module(new rv64.RegFile(Xlen))
    
    en :=  Mux(io.rd.orR, true.B , false.B) 
    // data := io.data
    data := Mux(en,io.data | 0.U,0.U)
    // rd := io.rd
    rd := Mux(en,io.rd | 0.U,0.U)
    
    regFileInst.io.waddr := rd
    regFileInst.io.wdata := data
    regFileInst.io.wen := en

    regFileInst.io.raddr1 := DontCare
    regFileInst.io.raddr2 := DontCare
    regFileInst.io.rdata1 := DontCare
    regFileInst.io.rdata2 := DontCare
    regFileInst.io.ren := DontCare
}