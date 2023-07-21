import chisel3._
import chisel3.util._

class Add(width: Int) extends Module {
  val io = IO(new Bundle {
      val in1 = Input(UInt(width.W))
      val in2 = Input(UInt(width.W))
      val out = Output(UInt(width.W))
  })
  io.out := io.in1 + io.in2
}

println(getVerilog(new Add(10)))
println(getVerilog(new Add(20)))

