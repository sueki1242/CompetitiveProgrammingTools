def test(file, input, output)
  File.write("input.txt", input)
  result=`#{file} < input.txt`
  if result.split == output.split
    puts "PASS"
  else
    puts "FAIL"
    puts "Expected:"
    puts output
    puts "Returned:"
    puts result
  end
end

if ARGV.length < 1 && ARGV.length > 2
  puts "usage: test.rb {problem name} ({case #})"
  exit
end

if ARGV.length < 2
  try = -1
else
  try = ARGV[1].to_i
end

# initialize
input = ""
output = ""
inputs = []
outputs = []
f_input = false
f_output = false

#testcase read loop
IO.foreach("#{ARGV[0]}.txt") do |line|
  if(line == "input\n")
    f_input = true
    f_output = false
    if input != ""
      inputs.push input
      outputs.push output
    end
    input = ""
    output = ""
  elsif(line == "output\n")
    f_input = false
    f_output = true
  elsif f_input
    input += line
  elsif f_output
    output += line
  end
end

inputs.push input
outputs.push output

for i in 0..(inputs.length-1) do
  if (try < 0 || try == i+1)
    print "case #" + (i+1).to_s + " : "
    test(ARGV[0], inputs[i], outputs[i])
  end
end

File.unlink "input.txt"