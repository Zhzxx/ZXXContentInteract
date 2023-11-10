#
#  Be sure to run `pod spec lint ZXXContentInteract.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "ZXXContentInteract"
  s.version      = "0.0.8"
  s.summary      = "ZXXContentInteract的一个简单示范工程."

  s.description  = <<-DESC
                   ZXXContentInteract的一个简单示范工程示范工程的长描述.
                   DESC

  s.homepage     = "https://github.com/Zhzxx/ZXXContentInteract"

  s.license      = "MIT"

  s.author       = { "ZXX" => "zxxiosmail@163.com" }

  s.platform     = :ios, "12.0"

  s.source       = { :git => "https://github.com/Zhzxx/ZXXContentInteract.git", :tag => "#{s.version}" }

  #s.preserve_paths = 'Demos', '.cocoapods.yml', "#{s.name}.podspec.json", "#{s.name}/src/oc/module.modulemap", "#{s.name}/src/oc/ZXXContentInteractOCHeader.h"

  s.swift_versions = ['5.0']
  
  s.user_target_xcconfig = { 'LIBRARY_SEARCH_PATHS' => '$(TOOLCHAIN_DIR)/usr/lib/swift/$(PLATFORM_NAME) $(TOOLCHAIN_DIR)/usr/lib/swift-5.0/$(PLATFORM_NAME)' }
  s.pod_target_xcconfig = {
    # 路径根据实际情况进行引用，必须保证路径是正确的
    'SWIFT_INCLUDE_PATHS' => ["$(PODS_ROOT)/#{s.name}/src/oc", "$(PODS_TARGET_SRCROOT)/#{s.name}/src/oc"]
  }
  s.default_subspecs = 'Core'

  s.subspec 'Core' do |core|
    #core.dependency 'SDWebImage'
    core.dependency 'OpenSSL-Universal', '~> 1.0.2.10'
    core.dependency 'Masonry', '~>1.1.0'
    core.dependency 'AFNetworking', '~>4.0.1'
    core.dependency 'FMDB', '~>2.7.5'
    core.dependency 'MBProgressHUD', '~>1.2.0'
    core.dependency 'Toast', '~>4.0.0'

    core.vendored_frameworks = "ZXXContentInteract.xcframework" 
    #core.public_header_files = "ZXXContentInteract.framework/Headers/*.h"
    core.resource_bundles = {
      "#{s.name}" => ["ZXXContentInteractBundle/*.{jpg,png,xib,strings,plist,bundle}"]
    }
    
  end

  s.post_install do |installer|
    # fix xcode 15 DT_TOOLCHAIN_DIR - remove after fix oficially - https://github.com/CocoaPods/CocoaPods/issues/12065
    installer.aggregate_targets.each do |target|
        target.xcconfigs.each do |variant, xcconfig|
        xcconfig_path = target.client_root + target.xcconfig_relative_path(variant)
        IO.write(xcconfig_path, IO.read(xcconfig_path).gsub("DT_TOOLCHAIN_DIR", "TOOLCHAIN_DIR"))
        end
    end
    installer.pods_project.targets.each do |target|
      target.build_configurations.each do |config|
        if config.base_configuration_reference.is_a? Xcodeproj::Project::Object::PBXFileReference
            xcconfig_path = config.base_configuration_reference.real_path
            IO.write(xcconfig_path, IO.read(xcconfig_path).gsub("DT_TOOLCHAIN_DIR", "TOOLCHAIN_DIR"))
        end
      end
    end
  end

end
