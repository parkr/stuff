require "stringex"

def ask(message, valid_options)
  if valid_options
    answer = get_stdin("#{message} #{valid_options.to_s.gsub(/"/, '').gsub(/, /,'/')} ") while !valid_options.include?(answer)
  else
    answer = get_stdin(message)
  end
  answer
end

def get_stdin(message)
  print message
  STDIN.gets.chomp
end

def create(title)
  filename = "_posts/#{Time.now.strftime('%Y-%m-%d')}-#{title.to_url}.markdown"
  if File.exist?(filename)
    abort("rake aborted!") if ask("#{filename} already exists. Do you want to overwrite?", ['y', 'n']) == 'n'
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
  filename
end

desc "Add a stuff"
task :new, :title do |t, args|
  if args.title && !args.title.empty?
    title = args.title
  else
    title = get_stdin("Enter a title for your post: ")
  end

  filename = create(title)
  puts filename
  sh "vim", filename
  sh "git", "add", filename
  sh "git", "commit", "-m \"Add '#{title.gsub(/"/, '\"')}'\""
end
