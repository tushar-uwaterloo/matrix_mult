LEN ?= 8
DW  ?= 8
N   ?= 8

mat_vect_mult2:
	rm -Rf obj_dir
	verilator -CFLAGS "-DN=$(LEN)" -cc mat_vect_mult2.v --exe mat_vect_mult2_tb.c -GN=${LEN} -GDW=${DW}
	make -C obj_dir -j -f Vmat_vect_mult2.mk Vmat_vect_mult2
	./obj_dir/Vmat_vect_mult2

mat_vect_mult2_vcd:
	verilator -trace -CFLAGS "-DTRACE, -DN=$(LEN)" -cc mat_vect_mult2.v --exe mat_vect_mult2_tb_trace.c -GN=${LEN} -GDW=${DW}
	make -C obj_dir -j -f Vmat_vect_mult2.mk Vmat_vect_mult2
	./obj_dir/Vmat_vect_mult2

hardware-report: run_yosys.ys
	yosys -s run_yosys.ys > hardware-report

%.pdf : %.md %_deps
	pandoc -Mfignos-star-name=Figure -Mfignos-plus-name=figure -Mfignos-cleveref=On --dpi 144 --filter pandoc-fignos -o $@ $<

lab2-wavedrom.png lab2-wavedrom.json: verilator.vcd
	python parse.py -o lab2-wavedrom -- $^
	convert -background none -density 144 lab2-wavedrom.svg lab2-wavedrom.png 
	rm lab2-wavedrom.svg

lab2-report_deps: lab2-wavedrom.png lab2-screenshot.png

clean::
	rm -rf obj_dir
	rm *.pdf


doc: lab2-report.pdf

mat_vect_mult.v: mat_vect_mult2.v
	cp $^ $@
mat_vect_mult_tb.c: mat_vect_mult2_tb.c
	cp $^ $@
mat_vect_mult_tb_trace.c: mat_vect_mult2_tb_trace.c
	cp $^ $@

lab2_deliverables = mat_vect_mult.v \
										mat_vect_mult_tb.c \
										mat_vect_mult_tb_trace.c \
										lab2-wavedrom.png \
										lab2-wavedrom.json \
										lab2-screenshot.png \
										lab2-report.pdf \
										hardware-report \
										vivado_report


lab2.tar.gz: $(lab2_deliverables)
	tar -czvf $@ $^
	@echo "****** Deliverables Packed."
	rm mat_vect_mult.v
	rm mat_vect_mult_tb.c
	rm mat_vect_mult_tb_trace.c
