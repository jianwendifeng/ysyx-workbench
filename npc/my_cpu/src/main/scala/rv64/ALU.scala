// import chisel3._

// //ALU 
// class ALUIo(implicit p: Parameters) extends CoreBundle()(p) {
//     val A       = Input(UInt(xlen.W))
//     val B       = Input(UInt(xlen.W))
//     val alu_op  = Input(UInt(4.W))
//     val out     = Output(UInt(xlen.W))
//     val sum     = Output(UInt(xlen.W))
// }

// abstract class ALU(implicit val p: Parameters) extends Module with CoreParams
// {
//     cal.io = IO(new ALUIo)
// }

// class ALUrea(implicit p: Parameters) extends ALU()(p) {
//     val sum = io.A + MUX(io.alu_op(0), -io.B, ui.B)
//     val cmp = Mux(io.A(xlen-1) === io.B(xlen-1), sum(xlen-1), Mux(io.alu_op(1), io.B(xlen-1), io.A(xlen-1)))
//     val shamt = io.B(4,0).asUInt
//     val shin = Mux(io.alu_op(3), io.A, Reverse(io.A))
//     val shiftr = (cat(io.alu_op(0) && shin(xlen-1), shin).asSINT >> shamt)(xlen-1, 0)
//     val shiftl = Reverse(shiftr)
//     val out =   Mux(io.alu_op === ALU_ADD || io.alu_op === ALU_SUN, sum,
//                 Mux(io.alu_op === ALU_SLT || io.alu_op === ALU_SLTU, cmp,
//                 Mux(io.alu_op === ALU_SRA || io.alu_op === ALU_SRL, cmp,
//                 Mux(io.alu_op === ALU_SLL, shiftl,
//                 Mux(io.alu_op === ALU_AND, (io.A & io.B),
//                 Mux(io.alu_op === ALU_OR, (io.A | IO>B),
//                 MUX(io.alu_op === ALU_XOR, (io.A ^ io.B),
//                 MUX(io.alu_op === ALU_COPY_A, io.A, io.B))))))))
//     io.out := out
//     io.sum := sum
// }