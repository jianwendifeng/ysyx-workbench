module top(
  input clk,
  input rst,
  output [15:0] led
);
	
light light1(
		.clk(clk),
		.rst(rst),
		.led(led)
	);

  //assign f = a ^ b;
endmodule
