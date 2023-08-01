// package rv64

// import chisel3._
// import chisel3.tuil._

// object Alu {
//     val ALU_ADD = 0.U(4.W)
//     val ALU_SUB = 1.U(4.W)
//     val ALU_AND = 2.U(4.W)
//     val ALU_OR = 3.U(4.W)
//     val ALU_XOR = 4.U(4.W)
//     val ALU_SLL = 5.U(4.W)
//     val ALU_SLT = 6.U(4.W)
//     val ALU_SLTU = 7.U(4.W)
//     val ALU_SRA = 8.U(4.W)
//     val ALU_SRL = 9.U(4.W)
    
//     val ALU_XXX = 15.U(4.W)
// }

// class AluIO(width: Int) extends Bundle {
//     val alu_op = Input(UInt(4.W))
//     val A = Input(UInt(width.W))
//     val B = Input(UInt(width.W))
//     val out = Output(UInt(width.W))
//     val sum = Output(UInt(width.W))
// }

// trait Alu extends Module {
//     def width: Int
//     val io: AluIO
// }

// class AluSimple(val width: Int) extends Alu {
//     val io = Io(new AluIO(width))

//     val shamt = io.B(4, 0).asUInt

//     io.out := MuxLookup(
//         io.alu_op,
//         io.B,
//         Seq(
//             ALU_ADD -> (io.A + io.B)
//             // ALU_SUB -> (io.A - io.B)
//             // ALU_AND -> (io.A & io.B)
//             // ALU_OP  -> (io.A | io.B)
//             // ALU_XOR -> (io.A ^ io.B)
//             // ALU_SLL -> (io.A << shamt)
//             // ALU_SLT -> (io.A.asSInt  < io.B.asSInt)
//             // ALU_SLTU -> (io.A < io.B)
//             // ALU_SRA -> (io.A.asSInt >> shamt).asSInt
//             // ALU_SRL -> (io.A.asSInt >> shanmt)

//         )
//     )

//     io.sum := io.A + Mux(io.alu_op(0), -io.B, io.B)
// }
