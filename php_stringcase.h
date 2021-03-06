
#ifndef PHP_STRINGCASE_H
#define PHP_STRINGCASE_H

extern zend_module_entry stringcase_module_entry;
#define phpext_stringcase_ptr &stringcase_module_entry

#define PHP_STRINGCASE_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_STRINGCASE_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_STRINGCASE_API __attribute__ ((visibility("default")))
#else
#	define PHP_STRINGCASE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(stringcase);
PHP_MSHUTDOWN_FUNCTION(stringcase);
PHP_RINIT_FUNCTION(stringcase);
PHP_RSHUTDOWN_FUNCTION(stringcase);
PHP_MINFO_FUNCTION(stringcase);

PHP_FUNCTION(confirm_stringcase_compiled);	/* For testing, remove later. */
PHP_FUNCTION(studly_case);
PHP_FUNCTION(snake_case);
PHP_FUNCTION(camel_case);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(stringcase)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(stringcase)
*/

/* In every utility function you add that needs to use variables 
   in php_stringcase_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as STRINGCASE_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define STRINGCASE_G(v) TSRMG(stringcase_globals_id, zend_stringcase_globals *, v)
#else
#define STRINGCASE_G(v) (stringcase_globals.v)
#endif

#endif	/* PHP_STRINGCASE_H */

