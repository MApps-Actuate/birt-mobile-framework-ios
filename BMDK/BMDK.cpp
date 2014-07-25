//
//  BMDK.cpp
//
//  BMDK is a Mobile Development Kit that gives developers an easy way
//  to write BIRT application with Mobile platforms in mind. It makes
//  heavy use of Actuate's JSAPI.
//
//  Copyright (c) 2014 Actuate Corporation. All rights reserved.
//

#include "BMDK.h"

class BMDK {
    /**
     * @param OutputType An enum that's used to tell BMDK what output type to use.
     */
    public: enum OutputType {WebViewer, HTML, PDF, XLS, XLSX,
                             ODP, ODS, ODT, PS, PPT, PPTX, DOC, DOCX};
    
    // Private variables
    private: std::string        username;
    private: std::string        password;
    private: std::string        host;
    private: std::string        volume;
    private: std::string        key;
    //private: Cipher              ecipher;
    //private: Cipher              dcipher;
    //private: MessageDigest       MD5;
    private: const std::string  rptListing          = "<html><head><meta http-equiv='content-type' content='text/html;charset=utf-8' /><title>Report Explorer Page</title></head><body onload='init( )'><input type='button' style='width: 150pt;' value='View Report' onclick='javascript:displayReport( )' /><hr /><div id='explorerpane'><script type='text/javascript' language='JavaScript' src='host/iportal/jsapi'></script><script type='text/javascript' language='JavaScript'>var file = 'unknown';function init() {actuate.load('reportexplorer');actuate.load('viewer');actuate.load('dialog');requestOpts = new actuate.RequestOptions();actuate.initialize('host/iportal',requestOpts, 'username', 'password', runReportExplorer);}function runReportExplorer() {var explorer = new actuate.ReportExplorer('explorerpane');explorer.registerEventHandler(actuate.reportexplorer.EventConstants.ON_SELECTION_CHANGED, selectionChanged);explorer.setFolderName('/Home/devSite');var resultDef ='Name|FileType|Version|VersionName|Description';explorer.setResultDef(resultDef.split('|'));explorer.submit();}function selectionChanged(selectedItem, pathName) {file = pathName;}function displayReport() {var y = document.getElementById('explorerpane'),child;while (child = y.firstChild) {y.removeChild(child);}var viewer = new actuate.Viewer('explorerpane');try {viewer.setReportName(file);viewer.submit();} catch (e) {alert('Selected file is not viewable: ' + file);runReportExplorer();}}</script></div></body></html>";
    private: const std::string  rptListingMD5       = createHash(rptListing);
    private: const std::string  viewReport          = "<script type='text/javascript' language='JavaScript' src='host/iportal/jsapi'></script><script type='text/javascript'>actuate.load('viewer');var reqOps = new actuate.RequestOptions();reqOps.setVolume('volume');reqOps.setCustomParameters({});actuate.initialize('http://demo.actuate.com/iportal/', reqOps == undefined ? null : reqOps, 'username', 'password', myInit);function myInit() {viewer1 = new actuate.Viewer('container1');viewer1.setReportDesign('report');var options = new actuate.viewer.UIOptions();viewer1.setUIOptions(options);viewer1.submit();}</script><div id='container1' style='border-width: 0px; border-style: solid;'></div>";
    private: const std::string  viewReportMD5       = createHash(viewReport);
    private: const std::string  viewReportType      = "host/iportal/executereport.do?__locale=en_US&__vp=volumename&volume=volumename&closex=true&__executableName=reportname&__requesttype=immediate&__format=formattype";
    private: const std::string  viewReportTypeMD5   = createHash(viewReportType);
    
    public: BMDK() {
        
    };
    
    /**
     * BMDK constructor with parameters. This allows you to create
     * a new BMDK object and pass in username, passwork, host,
     * and volume at the same time.
     * @param username
     * @param password
     * @param host
     * @param volume
     */
    public: BMDK(std::string username, std::string password, std::string host, std::string volume) {
        
    };
    
    /**
     * Creates a hash for security. This allows us to make sure
     * that none of the private variables have been tampered with
     * @param toHash The string that will be hashed
     * @return The final hash of what has been passed in
     */
    private: std::string createHash(std::string toHash) {
        return "dummy string";
    };
    
    /**
     * Generates a report using Actuate's JSAPI and returns it in the format
     * given via OutputType
     * @param reportName Name of the report to be exported. This must be the full path. IE /Home/devSite/test.rptdesign
     * @param outputType The format the report needs to be rendered in. IE xls, pdf, doc, etc.
     * @return Returns the report as a string for the developer to decide how to handle the contents
     */
    public: std::string exportReport(std::string reportName, OutputType outputType) {
            return "dummy string";
    }
    
    private: std::string regexJsapi(std::string format, std::string reportName) {
        std::string temp = *new std::string();
        return temp;
    };
    
    /**
     * This will login to the iHub and save the authenticated session in methods
     * such as exportReport()
     * @return Authenticated session
     */
    private: std::string login() {
        // TODO: Use the JSAPI to login and store the
        // authenticated session to add security to
        // exportReport()
        std::string session = "";
        return session;
    };
    
    /** 
     * Grabs the report in whatever format has been specified
     * @param url URL that forces the iHub to generate the report
     * @return The report in it's secified format
     */
    private: std::string getContent(std::string url) {
        return "dummy";
    };
    
    /**
     * @return Report listing in the specified volume as HTML string
     */
    public: std::string reportListing() {
        return "dummy";
    };
    
    /**
     * Takes a string, encrypts it, then returns the encrypted string
     * @param password Text to be encrypted
     * @return Encrypted text
     */
    private: std::string encrypt(std::string password) {
        std::string encPass = "";
        return encPass;
    };
    
    /**
     * Decrypts the string that has been passed to it
     * @param password String to decrypt
     * @return Decrypted string
     */
    private: std::string decrypt(std::string password) {
        std::string decrypted = *new std::string();
        return decrypted;
    };
    
    /**
     * Sets the username
     * @param username Username
     */
    public: void setUsername(std::string username) {

    };

    /**
     * Sets the password
     * @param password Password
     */
    public: void setPassword(std::string password) {
        
    };
    
    /**
     * Sets the host
     * @param host Host name
     */
    public: void setHost(std::string host) {
    
    };
    
    /**
     * Sets the volume
     * @param volume Volume name
     */
    public: void setVolume(std::string volume) {
        
    };
    
    /**
     * Gets the username
     * @return username
     */
    public: std::string getUsername() {
        return this->username;
    };
    
    /**
     * Gets the password
     * @return password
     */
    public: std::string getPassword() {
        return this->password;
    };
    
    /**
     * Gets the host
     * @return host
     */
    public: std::string getHost() {
        return this->host;
    };
    
    /**
     * Gets the volume
     * @return volume
     */
    public: std::string getVolume() {
        return this->volume;
    };
    
};




