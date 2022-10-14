#
#  Be sure to run `pod spec lint SDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "SDK"
  spec.version      = "0.0.1"
  spec.summary      = "A short description of SDK."
  spec.description  = <<-DESC
  asdfasd
                   DESC

  spec.homepage     = "https://www.conecta.mx/"
  spec.license      = "MIT"

  spec.author             = { "Irving Sanchez" => "irving@endcom.mx" }
  
  
  spec.platform     = :ios, "14.7"


  spec.source       = { :http => 'https://github.com/desarrollo-endcom/SDK/releases/download/0.0.1/SDK.framework.zip' }

  spec.ios.vendored_frameworks = 'SDK.framework'
  spec.swift_version = "5.1"

end
