package rv64

import chisel3._
import chisel3.util._
import ALU_Signals._

object ALU_Signals{
    val ALU_ADD  = 0.U(4.W)
    val ALU_SUB  = 1.U(4.W)
    val ALU_OR   = 2.U(4.W)
    val ALU_AND  = 3.U(4.W)
    val ALU_XOR  = 4.U(4.W)
    val ALU_SLL  = 5.U(4.W)
    val ALU_SRL  = 6.U(4.W)
    val ALU_SRA  = 7.U(4.W)
    val ALU_SLT  = 8.U(4.W)
    val ALU_SLTU = 9.U(4.W)
  
    val ALU_XXX  = 15.U(4.W)
}



class ALU(Xlen: Int) extends Module {
    val io = IO(new ALUIO(Xlen))
    val shamt = io.b(4,0).asUInt

    io.result := MuxLookup(io.ctr_signals_in.alu_sel, 0.U, Array(
        ALU_ADD     -> (io.a + io.b),
        ALU_SUB     -> (io.a - io.b),
        ALU_OR      -> (io.a | io.b),
        ALU_AND     -> (io.a & io.b),
        ALU_XOR     -> (io.a ^ io.b),
        ALU_SLL     -> (io.a << shamt),
        ALU_SRL     -> (io.a >> shamt),
        ALU_SRA     -> (io.a.asSInt >> shamt).asUInt,
        ALU_SLT     -> (io.a.asSInt < io.b.asSInt),
        ALU_SLTU    -> (io.a < io.b)
    ))

}