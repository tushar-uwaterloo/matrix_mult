#include "Vmat_vect_mult2.h"
#include "verilated.h"
#ifdef TRACE
#include <verilated_vcd_c.h>
#endif
#include <iostream>
using namespace std;

int main(int argc, char **argv, char **env) {
	Verilated::commandArgs(argc, argv);
	Vmat_vect_mult2* top = new Vmat_vect_mult2;
	int time=0;
	bool clk=0;
	int s_axis_tdata[N][N];
        int vect[N];
        int s_axis_tvalid;
        int s_axis_tlast;
        int m_axis_tready;
        int sw_result[N];
        int hw_result[N];
        int sum=0;
        int p=0;
        int q=0;
        int r=0;
        int s=0;
#ifdef TRACE
	Verilated::traceEverOn(true);
	VerilatedVcdC   *m_trace;
	m_trace = new VerilatedVcdC;
	top->trace(m_trace,99);
	m_trace->open("verilator.vcd");
#endif
        //initializing matrix
        for (int i=0; i<N; i++) {
          for (int j=1; j<=N; j++) {
            s_axis_tdata[i][j-1] = i+j;
          };
        };

        //initializing vector
        for (int i=1; i<=N; i++) {
          vect[i-1] = i;
        };
       
        //software calculation
        for (int c = 0; c < N; c++) {
            for (int k = 0; k < N; k++) {
              sum = sum + s_axis_tdata[c][k]*vect[k];
            }
            sw_result[c] = sum;
            sum = 0;
        }

	top->areset = 1;
	top->aclk = 0;
	cout << "// Verilator sim starting.." << endl;
	while (!Verilated::gotFinish() && time <=80) {
		top->areset = (time<2); top->aclk = clk;
                top->s_axis_tdata = s_axis_tdata[p][q];
                top->inp_vect = vect[s];
                top->s_axis_tvalid = 1;

                //if (s!=N-1) top->inp_vect_valid = 1;
                //else top->inp_vect_valid=0;
                top->inp_vect_valid=1;
                if (q==N-1) top->s_axis_tlast = 1;
                else      top->s_axis_tlast = 0;
                
                top->m_axis_tready = top->m_axis_tvalid;
                if (q==N-1 && time%2!=0) {
                  //top->s_axis_tlast = 1;
                  q=0;
                  if (p!=N-1) p=p+1;
                  else        p=0;  
                };
                if (top->s_axis_tready && !top->s_axis_tlast && time%2!=0) {
                  q = q+1;
                  if (s!=N-1) s=s+1;
                };
		top->eval();
		clk=!clk;
		time++;
		if (top->m_axis_tvalid && top->m_axis_tready && time%2!=0) {
                  hw_result[r] = top->m_axis_tdata;
                  if (r!=N-1) r=r+1;
                  else        r=N;
                }; 
#ifdef TRACE
		m_trace->dump(time);
		cout << "dumping trace" << endl;
#endif
	}
               
#ifdef TRACE
	m_trace->close();
#endif
        
	cout << "// Verilator sim done@" << time << endl;
	//cout << "// hardware result: " << hw_result << endl;
        for (int i=0; i<N; i++) {
          if (sw_result[i] != hw_result[i]) {
            cout << "sw_result " << sw_result[i] << "     hw_result" << hw_result[i];
            cout << "                     TEST FAILED !!" << endl;
          };
        };
        cout << "TEST PASSED !!" << endl;
     
	delete top;
	exit(0);
}

