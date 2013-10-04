guard :sass,
  :input => "_sass",
  :output => "css",
  :style => :compressed,
  :line_numbers => false

guard "jekyll-plus", serve: ENV["JEKYLL_SERVE"] do
  watch /.*/
  ignore /^_site/
end
