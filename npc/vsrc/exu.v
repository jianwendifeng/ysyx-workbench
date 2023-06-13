//`define OP_ADDI 7'b0010011
//`define FUNCT3_ADDI 3'b000

module exu(
	input [6:0] ex_op,
	input [31:0] ex_src1,
	input [11:0] ex_imm,
	input [14:12] ex_funct3,
	output reg [31:0] ex_result
);



	always @(*) begin
	case (ex_op)
		7'b0010011 : begin
			case (ex_funct3)
				3'b000:  ex_result = ex_src1 + {20'b0,ex_imm};	//clk use <= ,this not have clk
				default: ex_result = 32'b0;
			endcase
		end
		default: ex_result = 32'b0;
	endcase
end
endmodule
