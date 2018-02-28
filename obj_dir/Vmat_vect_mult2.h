// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vmat_vect_mult2_H_
#define _Vmat_vect_mult2_H_

#include "verilated.h"
class Vmat_vect_mult2__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vmat_vect_mult2) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(aclk,0,0);
    VL_IN8(areset,0,0);
    VL_IN8(inp_vect,7,0);
    VL_IN8(inp_vect_valid,0,0);
    VL_OUT8(inp_vect_rdy,0,0);
    VL_IN8(s_axis_tdata,7,0);
    VL_IN8(s_axis_tvalid,0,0);
    VL_IN8(s_axis_tlast,0,0);
    VL_OUT8(s_axis_tready,0,0);
    VL_OUT8(m_axis_tvalid,0,0);
    VL_OUT8(m_axis_tlast,0,0);
    VL_IN8(m_axis_tready,0,0);
    VL_OUT(m_axis_tdata,17,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(mat_vect_mult2__DOT__count,1,0);
    VL_SIG8(mat_vect_mult2__DOT__slice,1,0);
    //char	__VpadToAlign22[2];
    VL_SIG8(mat_vect_mult2__DOT__inp_vect_lat[4],7,0);
    VL_SIG8(mat_vect_mult2__DOT__inp_vect_reg[4],7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__aclk,0,0);
    VL_SIG8(__Vclklast__TOP__areset,0,0);
    //char	__VpadToAlign38[2];
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmat_vect_mult2__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vmat_vect_mult2& operator= (const Vmat_vect_mult2&);	///< Copying not allowed
    Vmat_vect_mult2(const Vmat_vect_mult2&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vmat_vect_mult2(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmat_vect_mult2();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmat_vect_mult2__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmat_vect_mult2__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vmat_vect_mult2__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__3(Vmat_vect_mult2__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(Vmat_vect_mult2__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(Vmat_vect_mult2__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vmat_vect_mult2__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vmat_vect_mult2__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(Vmat_vect_mult2__Syms* __restrict vlSymsp);
    static void	_settle__TOP__2(Vmat_vect_mult2__Syms* __restrict vlSymsp);
    static void	traceChgThis(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
