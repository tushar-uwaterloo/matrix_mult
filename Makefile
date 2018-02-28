mat_vect_mult2:
	rm -Rf obj_dir
	verilator -CFLAGS "-DN=$(LEN)" -cc mat_vect_mult2.v --exe mat_vect_mult2_tb.c -GN=${LEN} -GDW=${DW}
	make -C obj_dir -j -f Vmat_vect_mult2.mk Vmat_vect_mult2
	./obj_dir/Vmat_vect_mult2

mat_vect_mult2_vcd:
	verilator -trace -CFLAGS "-DTRACE, -DN=$(LEN)" -cc mat_vect_mult2.v --exe mat_vect_mult2_tb_trace.c -GN=${LEN} -GDW=${DW}
	make -C obj_dir -j -f Vmat_vect_mult2.mk Vmat_vect_mult2
	./obj_dir/Vmat_vect_mult2

hw:
	yosys -s run_yosys.ys

