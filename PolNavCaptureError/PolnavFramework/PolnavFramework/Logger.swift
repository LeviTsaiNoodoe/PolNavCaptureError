//
//  Log.swift
//  Sunray
//
//  Created by 蘇柄臣 on 2016/1/5.
//  Copyright © 2016年 Noodoe. All rights reserved.
//

import Foundation
import os.log

public enum NDLogLevel: Int {
    case debug = 0
    case info
    case `default`
    case fault
    case error
    
    func osLogType() -> OSLogType {
        switch self {
        case .debug:
            return OSLogType.debug
        case .info:
            return OSLogType.info
        case .`default`:
            return OSLogType.default
        case .fault:
            return OSLogType.fault
        case .error:
            return OSLogType.error
        }
    }
}

open class Logger {
    
    static let defaultLogger = Logger()
    
    let osLog: OSLog
    
    private init() {
        osLog = OSLog(subsystem: "com.kymco.noodoe", category: "general")
    }
    
    init(_ subsystem: String, category: String) {
        osLog = OSLog(subsystem: subsystem, category: category)
    }
    
    func log(_ logLevel: NDLogLevel, _ dso: UnsafeRawPointer? = #dsohandle, message: StaticString, _ args: Any...) {
        #if DEBUG
            let _msg = String(format: String(describing: message), arguments: args.map({ ($0 as? NSString)?.utf8String ?? ($0 as? NSNumber)?.intValue ?? $0 }) as! [CVarArg])
            os_log("%{public}@", dso: dso, log: osLog, type: logLevel.osLogType(), _msg)
        #else
            let _args = args.map({ ($0 as? NSString)?.utf8String ?? ($0 as? NSNumber)?.intValue ?? $0 }) as! [CVarArg]
            os_log(message, dso: dso, log: osLog, type: logLevel.osLogType(), _args)
        #endif
    }

    func writeLog(_ message: String, _ dso: UnsafeRawPointer? = #dsohandle, _ logLevel: NDLogLevel) {
        #if DEBUG
            os_log("[%{public}@] %{public}@", dso: dso, type: logLevel.osLogType(), String(describing: logLevel), message)
        #else
            os_log("%{public}@", dso: dso, type: logLevel.osLogType(), message)
        #endif
    }
    
    public static func debug(_ message: String, fileName: String = #file, funcName: String = #function, lineNum: Int = #line, _ dso: UnsafeRawPointer? = #dsohandle) {
        defaultLogger.writeLog(formatter(message, fileName, funcName, lineNum), dso, .debug)
    }
    
    public static func info(_ message: String, fileName: String = #file, funcName: String = #function, lineNum: Int = #line, _ dso: UnsafeRawPointer? = #dsohandle) {
        defaultLogger.writeLog(formatter(message, fileName, funcName, lineNum), dso, .info)
    }
    
    public static func `default`(_ message: String, fileName: String = #file, funcName: String = #function, lineNum: Int = #line, _ dso: UnsafeRawPointer? = #dsohandle) {
        defaultLogger.writeLog(formatter(message, fileName, funcName, lineNum), dso, .`default`)
    }
    
    public static func fault(_ message: String, fileName: String = #file, funcName: String = #function, lineNum: Int = #line, _ dso: UnsafeRawPointer? = #dsohandle) {
        defaultLogger.writeLog(formatter(message, fileName, funcName, lineNum), dso, .fault)
    }
    
    public static func error(_ message: String, fileName: String = #file, funcName: String = #function, lineNum: Int = #line, _ dso: UnsafeRawPointer? = #dsohandle) {
        defaultLogger.writeLog(formatter(message, fileName, funcName, lineNum), dso, .error)
    }
    
    private static func formatter(_ message: String, _ fileName: String, _ funcName: String, _ lineNum: Int) -> String {
        return "\(fileName.components(separatedBy: "/").last ?? "?")(\(lineNum))::\(funcName) - \(message)"
    }
}
