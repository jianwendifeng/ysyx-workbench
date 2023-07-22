module ifu(
	input clk,
	input rst,
	output reg [31:0] ifu_out
);

wire [31:0] pc_rom;

pc pc0(
	.clk(clk),
	.rst(rst),
	.pc_out(pc_rom)
);

inst_rom inst_rom0(
	.inst_addr(pc_rom),
	.inst_data(ifu_out)
);

endmodule
