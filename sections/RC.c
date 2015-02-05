extern int R_running_as_main_program;   /* in ../unix/system.c */

//For debugging purposes, use main instead of RC, then run make executable
//int main(int ac, char **av)
int RC(IEL_exec_info_t *exec_info)
{
	putenv("R_HOME=../../EXTLIB/R/inst/lib64/R");

	char *a0 = "RCcar";
	char *a1 = "--slave";
	char *a2 = malloc(sizeof(char));
	
//Option to get the R script name from the command line, instead of just script.r
	if(exec_info->modules[exec_info->module_num].mod_argc > 0){
		char tmp[40];  strcpy (tmp, "--file="); 
		strcat (tmp, exec_info->modules[exec_info->module_num].mod_argv[0]);
		a2 = tmp;
	}

	char** arguments = malloc(3*sizeof(char*));
	arguments[0] = a0;
	arguments[1] = a1;
	arguments[2] = a2;

	printf("Executing %s\n", arguments[2]);

	SEXP aleph, beth;
	R_running_as_main_program = 0;		//May do nothing?
	Rf_initialize_R(3, arguments); 		//R --slave --file=(filename)
	Rf_mainloop();

	return 0;
}
