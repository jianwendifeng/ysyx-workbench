package rv64
import chisel3._
import chisel3.util._
import ALU_Signals._
import Instructions._



object Decode {
    // //PC_SEL
    // val PC_SEL_LEN = 2
    // val PC_4 = 0.U(PC_SEL_LEN.W)
    // val PC_0 = 1.U(PC_SEL_LEN.W)
    // val PC_ALU = 2.u(PC_SEL_LEN.W)

    //A_SEl
    val A_SEL_LEN = 1
    val A_XXX = 0.U(A_SEL_LEN.W)
    val A_PC = 0.U(A_SEL_LEN.W)
    val A_RS1 = 1.U(A_SEL_LEN.W)

    //B_SEL
    val B_SEL_LEN = 1
    val B_XXX = 0.U(B_SEL_LEN.W)
    val B_IMM = 0.U(B_SEL_LEN.W)
    val B_RS2 = 1.U(B_SEL_LEN.W)

    //IMM_SEL
    val IMM_SEL_LEN = 3
    val IMM_X = 0.U(IMM_SEL_LEN.W)
    val IMM_I = 1.U(IMM_SEL_LEN.W)
    val IMM_U = 2.U(IMM_SEL_LEN.W)
    val IMM_S = 3.U(IMM_SEL_LEN.W)
    val IMM_J = 4.U(IMM_SEL_LEN.W)
    val IMM_B = 5.U(IMM_SEL_LEN.W)

    //RF_SEL
    // val RF_SEL_LEN = 1
    // val RF_XXX = 0.U(RF_SEL_LEN.W)
    val RF_N = false.B
    val RF_Y = true.B

    // //MEM_EN
    // val MEM_SEL_LEN = 1
    // val MEM_XXX = 0.U(MEM_SEL_LEN.W)
    val MEM_N = false.B
    val MEM_Y = true.B

    // //WB_EN
    // val WB_SEL_LEN = 1
    // val WB_XXX = 0.U(MEM_SEL_LEN.W)
    val WB_N = false.B
    val WB_Y = true.B

    val N = false.B
    val Y = true.B



    // format: off
    val default =
        List(ALU_XXX, A_XXX, B_XXX, IMM_X, RF_N, MEM_N, WB_N)     //RF_N  regfile不使能，RF_Y   regfile使能
    //                                                              kill                        wb_en  illegal?
    //             pc_sel  A_sel   B_sel  imm_sel   alu_op   br_type  |  st_type ld_type wb_sel  | csr_cmd |
    //               |       |       |     |          |          |    |     |       |       |    |  |      |
            //List(PC_4  , A_XXX,  B_XXX, IMM_X, ALU_XXX   , BR_XXX, N, ST_XXX, LD_XXX, WB_ALU, N, CSR.N, Y)        //riscv_mini format
    val map = Array(
        ADD   -> List(ALU_ADD,  A_RS1, B_RS2, IMM_X, RF_Y, MEM_N, WB_Y),
        ADDI  -> List(ALU_ADD,  A_RS1, B_IMM, IMM_I, RF_Y, MEM_N, WB_Y),
        AND   -> List(ALU_AND,  A_RS1, B_RS2, IMM_X, RF_Y, MEM_N, WB_Y),
        ANDI  -> List(ALU_AND,  A_RS1, B_IMM, IMM_I, RF_Y, MEM_N, WB_Y),
        AUIPC -> List(ALU_ADD,  A_PC,  B_IMM, IMM_U, RF_Y, MEM_N, WB_Y),
        SUB   -> List(ALU_SUB,  A_RS1, B_RS2, IMM_X, RF_Y, MEM_N, WB_Y),
        OR    -> List(ALU_OR,   A_RS1, B_RS2, IMM_X, RF_Y, MEM_N, WB_Y),
        ORI   -> List(ALU_OR,   A_RS1, B_IMM, IMM_X, RF_Y, MEM_N, WB_Y),
       
        XOR   -> List(ALU_XOR,  A_RS1, B_RS2, IMM_I, RF_Y, MEM_N, WB_Y),
        SLL   -> List(ALU_SLL,  A_RS1, B_RS2, IMM_X, RF_Y, MEM_N, WB_Y),
        SRL   -> List(ALU_SRL,  A_RS1, B_RS2, IMM_X, RF_Y, MEM_N, WB_Y),
        SRA   -> List(ALU_SRA,  A_RS1, B_RS2, IMM_X, RF_Y, MEM_N, WB_Y),
        SLT   -> List(ALU_SLT,  A_RS1, B_RS2, IMM_X, RF_Y, MEM_N, WB_Y),
        SLTU  -> List(ALU_SLTU, A_RS1, B_RS2, IMM_X, RF_Y, MEM_N, WB_Y),

    )
}


// class Decode_signals extends Bundle {
//     val inst = Input(UInt(32.W))
//     val alu_sel = Output(UInt(4.W))
//     val a_sel = Output(UInt(1.W))
//     val b_sel = Output(UInt(1.W))
//     val rf_en = Output(Bool())
//     val mem_en = Output(Bool())
//     val wb_en = Output(Bool())
// }

class Decode(Xlen: Int) extends Module 
{
    val io = IO(new DecodeIO(Xlen))
    val signals = ListLookup(io.inst,Decode.default,Decode.map)

    io.ctr_signals.alu_sel := signals(0)
    io.ctr_signals.a_sel := signals(1)
    io.ctr_signals.b_sel := signals(2)
    io.ctr_signals.imm_sel := signals(3)
    io.ctr_signals.rf_en := signals(4)
    io.ctr_signals.mem_en := signals(5)
    io.ctr_signals.wb_en := signals(6)   

}