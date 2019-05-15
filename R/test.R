#' Test Iconv
#'
#' Test the RIconv C API.
#'
#' @export
#' @param string input string
#' @param string to iconv output encoding
#' @useDynLib testiconv C_utf8_to_any
utf8_to_any <- function(string, to = 'latin1'){
  .Call(C_utf8_to_any, enc2utf8(string), to)
}
