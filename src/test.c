#include <iconv.h>
#include <stdlib.h>
#include <string.h>
#include <Rinternals.h>
#include <R_ext/Riconv.h>

SEXP C_utf8_to_any(SEXP input, SEXP enc){
	iconv_t cd = (iconv_t) Riconv_open(CHAR(STRING_ELT(enc, 0)), "UTF-8");
    if(cd == (iconv_t) -1)
    	Rf_error("Failed to init Riconv");

	const char * inbuf = CHAR(STRING_ELT(input, 0));
	size_t inlen = strlen(inbuf);
  size_t outlen = 4 * inlen + 1;
  char * output = (char *) malloc(outlen);
  char * cur = output;
  size_t success = Riconv(cd, &inbuf, &inlen,	&cur, &outlen);
 	if(success == (size_t) -1){
    return ScalarString(NA_STRING);
  }
  return mkString(output);
}
