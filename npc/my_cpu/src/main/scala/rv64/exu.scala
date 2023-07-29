package rv64

import chisel3._

class ExuIO(xlen: Int) extends Bundle {
    val io = IO(new Bundle{
        val op = Input(UInt(7.W))
        val in_rd = Input(UInt(5.W))
        val fun3 = Input(UInt(3.W))
        val immR = Input(UInt(7.W))
        val data1 = Input(UInt(64.W))
        val data2 = Input(UInt(64.W))
        val wen = Output(Bool())
        val out_rd = Output(UInt(5.W))
        val data = Output(UInt(64.W))
    })
}

class Exu extends Module {
    val io = IO(new ExuIO)
    val result = RegInit(0.U(32.W))
    val rd = RegInit(0.U(5.W))
    rd = io.in_rd

    when(io.op === 0110011){
        when(io.fun3 === 0000000 ){
            result := io.data1 + io.data2
        }
    }

    io.out_rd := rd
    io.data := result
}