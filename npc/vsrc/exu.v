`define OP_ADDI 0010011
`define FUNCT3_ADDI 000
module exu(
	input			 clk,
	input			 rst,
	input		[6:0] ex_opcode,
	input		[14:12] ex_funct3,
	input		[63:0] ex_src1,
	input		[31:20] ex_imm,
	output	[63;0] ex_data
);

always @	(posedge clk) begin
	if(clk) begin
		ex_data <= 64'b0;
	end
	else begin
			case (ex_opcode)
				OP_ADDI : if(ex_dunct3 == FUNCT3_ADDI) ex_data =  ex_src1 + imm ;
			endcase
	end
end

endmodule
