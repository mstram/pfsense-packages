<?php

function dashboard_install() {
	global $g, $config;
	assign_privs();
	if(!file_exists("/usr/local/www/index.php.before_dashboard")) {
		/* backup the pre-dashboard files */
		mwexec("mv /usr/local/www/index.php /usr/local/www/index.php.before_dashboard");
		mwexec("mv /usr/local/www/fbegin.inc /usr/local/www/fbegin.inc.before_dashboard");
		mwexec("mv /usr/local/www/diag_logs_filter.php /usr/local/www/diag_logs_filter.php.before_dashboard");
		mwexec("mv /usr/local/www/diag_logs_filter_dynamic.php /usr/local/www/diag_logs_filter_dynamic.php.before_dashboard");
	} else {
		/* Move the files, since we do not know what version they are, don't try to keep them. */
		mwexec("mv /usr/local/www/index.php /usr/local/www/index.php.tmp");
		mwexec("mv /usr/local/www/fbegin.inc /usr/local/www/fbegin.inc.tmp");
		mwexec("mv /usr/local/www/diag_logs_filter.php /usr/local/www/diag_logs_filter.php.tmp");
		mwexec("mv /usr/local/www/diag_logs_filter_dynamic.php /usr/local/www/diag_logs_filter_dynamic.php.tmp");
	}
	mwexec("tar xzvpf /usr/local/pkg/widgets.tgz -C /");
	assign_privs();
}

function dashboard_deinstall() {
	global $g, $config;
	assign_privs();
	if(file_exists("/usr/local/www/index.php.before_dashboard")) {
		/* restore the files prior to the dashboard package installation */
		mwexec("mv /usr/local/www/index.php.before_dashboard /usr/local/www/index.php");
		mwexec("mv /usr/local/www/fbegin.inc.before_dashboard /usr/local/www/fbegin.inc");
		mwexec("mv /usr/local/www/diag_logs_filter.php.before_dashboard /usr/local/www/diag_logs_filter.php");
		mwexec("mv /usr/local/www/diag_logs_filter_dynamic.php.before_dashboard /usr/local/www/diag_logs_filter_dynamic.php");
	}
	assign_privs();
}

function assign_privs() {
	/* Fix permissions on replaced files */
	mwexec("chown root:wheel /usr/local/www/index.php");
	mwexec("chown root:wheel /usr/local/www/fbegin.php");
	mwexec("chown root:wheel /usr/local/www/graph_cpu.php");
	mwexec("chown root:wheel /usr/local/www/stats.php");
	mwexec("chown root:wheel /usr/local/www/diag_logs_filter.php");
	mwexec("chown root:wheel /usr/local/www/diag_logs_filter_dynamic.php");
	mwexec("chmod ug+rw,o-w /usr/local/www/index.php");
	mwexec("chmod ug+rw,o-w /usr/local/www/fbegin.php");
	mwexec("chmod ug+rw,o-w /usr/local/www/graph_cpu.php");
	mwexec("chmod ug+rw,o-w /usr/local/www/stats.php");
	mwexec("chmod ug+rw,o-w /usr/local/www/diag_logs_filter.php");
	mwexec("chmod ug+rw,o-w /usr/local/www/diag_logs_filter_dynamic.php");
}

?>