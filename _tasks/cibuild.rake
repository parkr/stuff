require 'html/proofer'

task :cibuild do
  sh "bundle exec jekyll build --destination _site"
end
