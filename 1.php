<?php
class AccountManager
{{
	public function login(){
		echo "login successful\n";
	}
	public function logout(){
		echo "logout euccessful\n";
	}
}
$x = new AccountManager();
$x->login();
$x->logout();
