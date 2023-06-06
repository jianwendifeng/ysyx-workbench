

module ifu(
	input	clk,
	input [63:0] if_data,
	input [63:0] if_addr,
	input wen
);

	wire [63:0] id_rdata;
	RegisterFile #(64, 64) i0(clk,if_data,if_addr,wen,id_rdata);
endmodule
