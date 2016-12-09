# day1.rb
pos = 5
File.foreach("input").with_index do |ins, num|
	ins.each_char do |c|
		case c
		when "U"
			if [5, 2, 1, 4, 9].all? {|b| b != pos}							#if pos > 3
				pos != 3 && pos != 13? pos = pos - 4 : pos = pos - 2	#pos -= 3
			end
		when "D"
			if [5, 10, 12, 13, 9].all? {|b| b != pos} 					#if pos < 7
				pos != 11 && pos != 1? pos = pos + 4 : pos = pos + 2	#pos += 3
			end
		when "L"																			
			if [1, 2, 5, 10, 13].all? {|b| b != pos}						#if pos%3 != 1
				pos = pos - 1
			end
		when "R"
			if [1, 4, 9, 12, 13].all? {|b| b != pos}						#if pos%3 != 0
				pos = pos + 1
			end
		end
	end
	puts("Button number #{num} should be " + pos.to_s(16))			#just pos.to_s
end
