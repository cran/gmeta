#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP pvaluecombine(SEXP, SEXP, SEXP);

/* .Fortran calls */
extern void F77_NAME(confdistint)(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);

static const R_CallMethodDef CallEntries[] = {
    {"pvaluecombine", (DL_FUNC) &pvaluecombine, 3},
    {NULL, NULL, 0}
};

static const R_FortranMethodDef FortranEntries[] = {
    {"confdistint", (DL_FUNC) &F77_NAME(confdistint), 16},
    {NULL, NULL, 0}
};

void R_init_gmeta(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, FortranEntries, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
