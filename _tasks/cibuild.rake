require 'html/proofer'

task :cibuild do
  sh "bundle exec jekyll build --destination _site"
  HTML::Proofer.new(File.join(Dir.pwd, "_site")).run
end
