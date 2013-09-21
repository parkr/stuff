desc "Add a stuff for later"
task :for_later, :title do |t, args|
  if args.title
    title = args.title
  else
    abort "Look homie, you gotta provide a title. K?"
  end

  filename = "_posts/#{Time.now.strftime('%Y-%m-%d')}-#{title.to_url}.markdown"
  if File.exist?(filename)
    puts filename
    abort
  end
  open(filename, 'w') do |post|
    post.puts "---"
    post.puts "layout: post"
    post.puts "title: \"#{title.gsub(/&/,'&amp;')}\""
    post.puts "date: #{Time.now.strftime('%Y-%m-%d %H:%M:%S %z')}"
    post.puts "external-url: "
    post.puts "mirror: "
    post.puts "---"
  end
  puts filename
end
