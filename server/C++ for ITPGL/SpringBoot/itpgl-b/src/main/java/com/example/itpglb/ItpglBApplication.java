package com.example.itpglb;

import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.web.bind.annotation.*;
import org.springframework.http.ResponseEntity;

@SpringBootApplication
public class ItpglBApplication {

	public static void main(String[] args) {
		SpringApplication.run(ItpglBApplication.class, args);
	}

	
	public MongoClient mongoClient() {
		return MongoClients.create("mongodb://ITPGL:L5A8l0z6SSSok6PF@ac-szlyeyu-shard-00-00.28j8bcs.mongodb.net:27017,ac-szlyeyu-shard-00-01.28j8bcs.mongodb.net:27017,ac-szlyeyu-shard-00-02.28j8bcs.mongodb.net:27017/?ssl=true&replicaSet=atlas-p0bca1-shard-0&authSource=admin&retryWrites=true&w=majority&appName=ITPGL-cluster");
	}

	@RestController
	@RequestMapping("/users")
	public class UserController {
		private final UserService userService;

		public UserController(UserService userService) {
			this.userService = userService;
		}

		@RequestMapping(value = "/register/{username}/{email}/{firstName}/{lastName}/{password}", method = {RequestMethod.GET, RequestMethod.POST})
		public ResponseEntity<User> register(@PathVariable String username, @PathVariable String email, @PathVariable String firstName, @PathVariable String lastName, @PathVariable String password) {
			User user = new User();
			user.setUsername(username);
			user.setEmail(email);
			user.setFirstName(firstName);
			user.setLastName(lastName);
			user.setPassword(password);
			System.out.println(user);
			return ResponseEntity.ok(userService.register(user));
		}

		@GetMapping("/")
		public String hello() {
			return "";
		}
	}
}