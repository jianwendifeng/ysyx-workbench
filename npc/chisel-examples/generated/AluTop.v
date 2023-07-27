module Alu(
  input  [1:0] io_fn,
  input  [3:0] io_a,
  input  [3:0] io_b,
  output [3:0] io_result
);
  wire [3:0] _result_T_1 = io_a + io_b; // @[Alu.scala 34:27]
  wire [3:0] _result_T_3 = io_a - io_b; // @[Alu.scala 35:27]
  wire [3:0] _result_T_4 = io_a | io_b; // @[Alu.scala 36:27]
  wire [3:0] _result_T_5 = io_a & io_b; // @[Alu.scala 37:27]
  wire [3:0] _GEN_0 = 2'h3 == io_fn ? _result_T_5 : 4'h0; // @[Alu.scala 30:10 33:14 37:22]
  wire [3:0] _GEN_1 = 2'h2 == io_fn ? _result_T_4 : _GEN_0; // @[Alu.scala 33:14 36:22]
  wire [3:0] _GEN_2 = 2'h1 == io_fn ? _result_T_3 : _GEN_1; // @[Alu.scala 33:14 35:22]
  assign io_result = 2'h0 == io_fn ? _result_T_1 : _GEN_2; // @[Alu.scala 33:14 34:22]
endmodule
module AluTop(
  input        clock,
  input        reset,
  input  [9:0] io_sw,
  output [9:0] io_led
);
  wire [1:0] alu_io_fn; // @[Alu.scala 54:19]
  wire [3:0] alu_io_a; // @[Alu.scala 54:19]
  wire [3:0] alu_io_b; // @[Alu.scala 54:19]
  wire [3:0] alu_io_result; // @[Alu.scala 54:19]
  Alu alu ( // @[Alu.scala 54:19]
    .io_fn(alu_io_fn),
    .io_a(alu_io_a),
    .io_b(alu_io_b),
    .io_result(alu_io_result)
  );
  assign io_led = {{6'd0}, alu_io_result}; // @[Alu.scala 62:10]
  assign alu_io_fn = io_sw[1:0]; // @[Alu.scala 57:21]
  assign alu_io_a = io_sw[5:2]; // @[Alu.scala 58:20]
  assign alu_io_b = io_sw[9:6]; // @[Alu.scala 59:20]
endmodule
