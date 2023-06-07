`define OP_ADDI 0010011
`define FUNCT3_ADDI 000
module exu(
	input [31:0] src1,imm,
	output	[31:0] ex_data
);

assign ex_data = src1 + imm;

/*always @	(posedge clk) begin
	if(clk) begin
		ex_data <= 32'b0;
	end
	else begin
			case (ex_opcode)
				OP_ADDI : if(ex_dunct3 == FUNCT3_ADDI) ex_data =  ex_src1 + imm ;
			endcase
	end
end*/

endmodule
