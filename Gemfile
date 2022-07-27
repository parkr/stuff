source "https://rubygems.org"

require "json"
require "open-uri"
versions = ::JSON.parse(::URI.open("https://pages.github.com/versions.json").read)

gem "github-pages", versions["github-pages"]

group :development do
  gem 'rake'
  gem 'stringex'
end

group :test do
  gem 'html-proofer', '~> 4.3'
end

gem "webrick", "~> 1.7"
