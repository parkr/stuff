source "https://rubygems.org"

require "json"
require "open-uri"
versions = JSON.parse(open("https://pages.github.com/versions.json").read)

gem "github-pages", versions["github-pages"]

group :development do
  gem 'rake'
  gem 'stringex'
end

group :test do
  gem 'html-proofer', '~> 3.10'
end
