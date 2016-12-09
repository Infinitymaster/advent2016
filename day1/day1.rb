# day1.rb
File.open("input", "r") do |f|
	pos = [0, 0]
	breadcrmbs = {}
	breadcrmbs[pos] = 0
	heading = 0 # N = 0, E = 1, S = 2, W = 3
	found = false
	input = f.read.split(", ")
	
	input.each do |cmd|
		if cmd[0] == "R"
			heading = (heading + 1) % 4
		else 
			heading = (heading - 1) % 4
		end
		
		(1..cmd.slice(1, cmd.length).to_i).each do |n|
			if heading % 2 == 0 
				pos[0] += (heading - 1)
			else
				pos[1] += (heading - 2)
			end
			if breadcrmbs.key?(pos) 
				found = true
			else 
				breadcrmbs[pos] = 0
			end 
		break if found		#comment out for part 1
		end 
	
	break if found			#comment out for part 1
	end 
	dist = pos[0].abs + pos[1].abs  
	puts("Bunny HQ is #{dist} blocks away")
end
