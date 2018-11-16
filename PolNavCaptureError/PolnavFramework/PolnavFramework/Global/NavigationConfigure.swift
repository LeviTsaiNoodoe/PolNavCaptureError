//
//  NavigationConfigure.swift
//  LeviPolstarDemo
//
//  Created by LeviTsai on 2018/1/8.
//  Copyright © 2018年 LeviTsai. All rights reserved.
//

import Foundation

public class NavigationConfigure: NSObject, NSCoding {
    
    private var apsFolder: URL {
        return URL(fileURLWithPath: (NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true))[0])
    }
    
    private var configureFilePath: URL {
        return self.apsFolder.appendingPathComponent("NavigationConfigure")
    }
    
    @objc dynamic public var dayNightMode: DayNightMode = .auto {
        didSet{
            archieve()
        }
    }
    
    public var speedCamera: Bool = true {
        didSet{
            archieve()
        }
    }
    
    @objc dynamic public var routePriority: RoutePriority = .timeFirst {
        didSet{
            archieve()
        }
    }
    
    @objc dynamic public var avoidHighways: Bool = true {
        didSet{
            archieve()
        }
    }
    
    @objc dynamic public var avoidTolls: Bool = true {
        didSet{
            archieve()
        }
    }
    
    @objc dynamic public var avoidFerries: Bool = true {
        didSet{
            archieve()
        }
    }
    
    public var sortOption: FTSSortOption = FTSSortOption.distance {
        didSet{
            archieve()
        }
    }
    
    public var voiceCommand: String? {
        didSet{
            archieve()
        }
    }
    
    @objc public dynamic var muted: Bool = false {
        didSet {
            archieve()
        }
    }
    
    public enum Key: String {
        case DayNightMode
        case SpeedCamera
        case RoutePriority
        case AvoidHighways
        case AvoidTolls
        case AvoidFerries
        case FTSSortOption
        case VoiceCommand
        case muted
    }
    
    public override init() {
        super.init()

        NSKeyedUnarchiver.setClass(NavigationConfigure.self, forClassName: "Sunray.NavigationConfigure")
        if let object = NSKeyedUnarchiver.unarchiveObject(withFile: self.configureFilePath.path) as? NavigationConfigure {
            self.dayNightMode = object.dayNightMode
            self.speedCamera = object.speedCamera
            self.routePriority = object.routePriority
            self.avoidHighways = object.avoidHighways
            self.avoidTolls = object.avoidTolls
            self.avoidFerries = object.avoidFerries
            self.sortOption = object.sortOption
            self.muted = object.muted
            if let voiceCommand = object.voiceCommand {
                self.voiceCommand = voiceCommand
            }
        }
        
        self.archieve()
    }
    
    required public init?(coder aDecoder: NSCoder) {
        var n: UInt
        n = aDecoder.decodeObject(forKey: Key.DayNightMode.rawValue) as? UInt ?? DayNightMode.auto.rawValue
        dayNightMode = DayNightMode(rawValue: n) ?? .auto
        speedCamera = aDecoder.decodeBool(forKey: Key.SpeedCamera.rawValue)
        n = aDecoder.decodeObject(forKey: Key.RoutePriority.rawValue) as? UInt ?? RoutePriority.timeFirst.rawValue
        routePriority = RoutePriority( rawValue: n) ?? .timeFirst
        speedCamera = aDecoder.decodeBool(forKey: Key.SpeedCamera.rawValue)
        avoidHighways = aDecoder.decodeBool(forKey: Key.AvoidHighways.rawValue)
        avoidTolls = aDecoder.decodeBool(forKey: Key.AvoidTolls.rawValue)
        avoidFerries = aDecoder.decodeBool(forKey: Key.AvoidFerries.rawValue)
        n = aDecoder.decodeObject(forKey: Key.FTSSortOption.rawValue) as? UInt ?? FTSSortOption.default.rawValue
        sortOption = FTSSortOption( rawValue: n) ?? .default
        if let voiceName = aDecoder.decodeObject(forKey: Key.VoiceCommand.rawValue) as? String {
            self.voiceCommand = voiceName
        }
        
        if let muted = aDecoder.decodeObject(forKey: Key.muted.rawValue) as? Bool {
            self.muted = muted
        }
    }
    
    public func encode(with aCoder: NSCoder) {
        aCoder.encode(self.dayNightMode.rawValue, forKey: Key.DayNightMode.rawValue)
        aCoder.encode(self.speedCamera, forKey: Key.SpeedCamera.rawValue)
        aCoder.encode(self.routePriority.rawValue, forKey: Key.RoutePriority.rawValue)
        aCoder.encode(self.avoidHighways, forKey: Key.AvoidHighways.rawValue)
        aCoder.encode(self.avoidTolls, forKey: Key.AvoidTolls.rawValue)
        aCoder.encode(self.avoidFerries, forKey: Key.AvoidFerries.rawValue)
        aCoder.encode(self.sortOption.rawValue, forKey: Key.FTSSortOption.rawValue)
        aCoder.encode(self.voiceCommand, forKey: Key.VoiceCommand.rawValue)
        aCoder.encode(self.muted, forKey: Key.muted.rawValue)
    }
    
    func archieve() {
        NSKeyedArchiver.archiveRootObject(self, toFile: self.configureFilePath.path)
    }
}
