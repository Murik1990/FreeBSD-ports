--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2024-05-21 18:07:39 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -480,7 +480,7 @@ bool ChromePasswordManagerClient::ShowKeyboardReplacin
 
 bool ChromePasswordManagerClient::CanUseBiometricAuthForFilling(
     device_reauth::DeviceAuthenticator* authenticator) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!GetLocalStatePrefs() || !GetPrefs() || !authenticator) {
     return false;
   }
@@ -703,7 +703,7 @@ void ChromePasswordManagerClient::NotifyUserCredential
 }
 
 void ChromePasswordManagerClient::NotifyKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PasswordsClientUIDelegate* manage_passwords_ui_controller =
       PasswordsClientUIDelegateFromWebContents(web_contents());
   manage_passwords_ui_controller->OnKeychainError();
