mat_vect_mult1:
	rm -Rf obj_dir
	verilator -CFLAGS "-DN=$(LEN)" -cc mat_vect_mult1.v --exe mat_vect_mult1_tb.c -GN=${LEN} -GDW=${DW}
	make -C obj_dir -j -f Vmat_vect_mult1.mk Vmat_vect_mult1
	./obj_dir/Vmat_vect_mult1

mat_vect_mult1_vcd:
	verilator -trace -CFLAGS "-DTRACE, -DN=$(LEN)" -cc mat_vect_mult1.v --exe mat_vect_mult1_tb_trace.c -GN=${LEN} -GDW=${DW}
	make -C obj_dir -j -f Vmat_vect_mult1.mk Vmat_vect_mult1
	./obj_dir/Vmat_vect_mult1

mat_vect_mult2:
	rm -Rf obj_dir
	verilator -CFLAGS "-DN=$(LEN)" -cc mat_vect_mult2.v --exe mat_vect_mult2_tb.c -GN=${LEN} -GDW=${DW}
	make -C obj_dir -j -f Vmat_vect_mult2.mk Vmat_vect_mult2
	./obj_dir/Vmat_vect_mult2

mat_vect_mult2_vcd:
	verilator -trace -CFLAGS "-DTRACE, -DN=$(LEN)" -cc mat_vect_mult2.v --exe mat_vect_mult2_tb_trace.c -GN=${LEN} -GDW=${DW}
	make -C obj_dir -j -f Vmat_vect_mult2.mk Vmat_vect_mult2
	./obj_dir/Vmat_vect_mult2

vect_mult_seq_veri:
	rm -Rf obj_dir
	verilator -CFLAGS "-DN=$(LEN)" -cc vector_mult_seq.v --exe vector_mult_seq_tb.c -Gn=${LEN} -Gdw=${dw}
	make -C obj_dir -j -f Vvector_mult_seq.mk Vvector_mult_seq
	./obj_dir/Vvector_mult_seq

vect_mult_seq_veri_vcd:
	verilator -trace -CFLAGS "-DTRACE, -DN=$(LEN)" -cc vector_mult_seq.v --exe vector_mult_seq_tb_trace.c -Gn=${LEN} -Gdw=${dw}
	make -C obj_dir -j -f Vvector_mult_seq.mk Vvector_mult_seq
	./obj_dir/Vvector_mult_seq

