#include "json.hpp"

#include <tuple>
#include <vector>
#include <sstream>
#include <fstream>
#include <exception>
#include <algorithm>

#include <iostream>

using json = nlohmann::json;




#pragma region typedefs //{
	typedef std::vector<unsigned long long> ullvec;
	typedef std::tuple<std::string, std::string, std::string> str3;
	typedef std::vector<std::string> strvec;
	typedef std::vector<str3> str3vec;

#pragma endregion  //} typedefs

#pragma region declarations //{
	#pragma region json_append //{
		json
		json_append (
			const json& arg1,
			const json& arg2
		);
	#pragma endregion //} json_append
	#pragma region json_snippet //{
		json json_snippet(
			const std::string& title,
			const std::string& prefix,
			const std::string& body,
			const std::string& description
		);
		json json_snippet (
			const std::string& title,
			const std::string& prefix,
			const strvec& body,
			const std::string& description
		);
	#pragma endregion //} json_snippet

	#pragma region conversion_functions //{
		#pragma region convert_to_vscode_snippet //{
			std::string convert_to_vscode_snippet (
				const json& json_obj
			);
		#pragma endregion //} convert_to_vscode_snippet
		#pragma region convert_to_msvc_snippet //{
			std::string convert_to_msvc_snippet (
				const json& json_obj
			);
		#pragma endregion //} convert_to_vscode_snippet
	#pragma endregion //} conversion_functions

	#pragma region snippets //{
		namespace snippet {
			#pragma region region_snippet //{
				std::string region_str (
					std::string region_name,
					std::string str
				);
				json region();
			#pragma endregion //} region_snippet
			#pragma region function_snippet //{
				std::string function_str (
					std::string return_type,
					std::string function_name,
					std::string arguments,
					std::string body
				);
				std::string p_function_str (
					std::string return_type,
					std::string function_name,
					std::string arguments,
					std::string body
				);
				std::string function_body_str (
					std::string return_type,
					std::string body
				);
				std::string pb_function_str(
					std::string return_type,
					std::string function_name,
					std::string arguments,
					std::string body
				);

				json basic_function();
				json snippet_function();
				json p_function();
				json function_body();

				json pb_function();
			#pragma endregion //} function_snippet

			void generate(json snippet);
		}
		
		#pragma region non-templated //{
			#pragma region generate_nscfn_nth_snippet //{
				json
				generate_nscfn_nth_snippet (
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				);
				json
				generate_nscfn_nth_snippet(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::vector<std::pair<std::string, std::string>>& argv
				);
			#pragma endregion //} generate_nscfn_nth_snippet
			#pragma region generate_nscfn_snippets //{
				json
				generate_nscfn_snippets (
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				);
			#pragma endregion //} generate_nscfn_snippets

			#pragma region generate_cfn_nth_snippet //{
				json
				generate_cfn_nth_snippet(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				);
				json
				generate_cfn_nth_snippet(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::vector<std::pair<std::string, std::string>>& argv
				);
			#pragma endregion //} generate_cfn_nth_snippet
			#pragma region generate_cfn_snippets //{
				json
				generate_cfn_snippets(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				);
			#pragma endregion //} generate_cfn_snippets

			#pragma region generate_nfn_nth_snippet //{
				json
				generate_nscfn_nth_snippet (
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				);
				json
				generate_nsfn_nth_snippet (
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::vector<std::pair<std::string, std::string>>& argv
				);
			#pragma endregion //} generate_nsfn_nth_snippet
			#pragma region generate_nsfn_snippets //{
				json
				generate_nsfn_snippets(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				);
			#pragma endregion //} generate_nsfn_snippets

			#pragma region generate_fn_nth_snippet //{
				json
				generate_fn_nth_snippet(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				);
				json
				generate_fn_nth_snippet(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::vector<std::pair<std::string, std::string>>& argv
				);
			#pragma endregion //} generate_fn_nth_snippet
			#pragma region generate_fn_snippets //{
				json
				generate_fn_snippets(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				);
			#pragma endregion //} generate_fn_snippets
		#pragma endregion //} non-templated
		#pragma region templated //{
			#pragma region generate_tnscfn_nth_snippet //{
				json
				generate_tnscfn_nth_snippet (
					const std::string& title,
					const std::string& prefix,
					const std::size_t& argc
				);
				json
				generate_tnscfn_nth_snippet (
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::pair<std::string, std::string>>& argv
				);
			#pragma endregion //} generate_tnscfn_nth_snippet
			#pragma region generate_tnscfn_snippets //{
				json
				generate_tnscfn_snippets(
					const std::string& title,
					const std::string& prefix,
					const std::size_t& argc
				);
			#pragma endregion //} generate_tnscfn_snippets
		#pragma endregion }// templated
	#pragma endregion //} snippets
#pragma endregion //} declarations

#pragma region basic_functions //{
	#pragma region replace_all //{
		std::string& replace_all (
			std::string& src,
			const std::string &search,
			const std::string &replace
		) {
			for (std::size_t it2 = 0; it2 < src.size();) {
				it2 = src.find(search, it2);
				if (it2 != std::string::npos) {
					//std::cout << std::string(src.begin() + it2, src.begin() + it2 + search.size()) << std::endl;
					src.replace(it2, search.size(), replace);
					it2 += replace.size();
					//std::cout << src.size() << std::endl;
				} else {
					break;
				}
			}

			return src;
		}
	#pragma endregion //} replace_all
#pragma endregion //} basic_functions
#pragma region json_append //{
	json
	json_append (
		const json &arg1,
		const json &arg2
	)
	{
		#pragma region variables //{
			json result;

		#pragma endregion //} variables

		//TODO:
		for (json::const_iterator it = arg1.begin(); it != arg1.end(); it++) {
			result[it.key()] = it.value();
		}
		for (json::const_iterator it = arg2.begin(); it != arg2.end(); it++) {
			result[it.key()] = it.value();
		}

		return result;
	}
#pragma endregion //} json_append

#pragma region json_snippet //{
	json json_snippet (
		const std::string& title,
		const std::string& prefix,
		const std::string& body,
		const std::string& description
	) {
		#pragma region variables //{
			json result;
			strvec strvec_body;
			
		#pragma endregion //} variables

		strvec_body = [](const std::string &str) -> strvec {
			strvec result;
			std::string line;
			std::stringstream ss;
			ss.str(str);
			
			while (std::getline(ss, line, '\n')) {
				result.emplace_back(line);
			}

			return result;
		}(body);
		
		result = json_snippet (
			title,			// title
			prefix,			// prefix/shortcut
			strvec_body,	// body
			description		// description
		);
		

		return result;
	}
	json json_snippet (
		const std::string& title,
		const std::string& prefix,
		const strvec& body,
		const std::string& description
	) {
		#pragma region variables //{
			json result;
		#pragma endregion //} variables

		result[title]["prefix"] = prefix;
		result[title]["body"] = json(body);
		result[title]["description"] = description;

		return result;
	}
#pragma endregion //} json_snippet
#pragma region vscode_snippet //{
	std::string vscode_snippet (
		const std::string& title,
		const std::string& prefix,
		const strvec& body,
		const std::string& description
	) {
		std::string result;

		result = json_snippet(
			title,
			prefix,
			body,
			description
		).dump(true, '\t', true);

		return result;
	}
#pragma endregion //} vscode_snippet
#pragma region vscode_write //{
	void
	vscode_write (
		std::string filepath,
		json snippet
	) {
		std::ofstream file;
		std::string str;

		std::string filename = snippet.begin().key();
		replace_all(filename, " ", "_");

		str = convert_to_vscode_snippet(snippet);
		//std::cout << msvc_str << std::endl;

		filepath += filename + ".json";
		file.open(filepath);
		if (file.is_open()) {
			//std::cout << "writting to json file...\n";
			file << str;
		}
		else {
			std::cout << "could not open " << filepath << "\n";
		}
		file.close();
	}
#pragma endregion //} vscode_write

#pragma region msvc_literal //{
	std::string
	msvc_literal (
		const str3& literal
	) {
		#pragma region variables //{
			std::string _id;
			std::string _tooltip;
			std::string _default;

			std::stringstream ss;
		#pragma endregion //} variables

		std::tie(_id, _tooltip, _default) = literal;

		ss << "\t\t\t\t<Literal>\n"
			<< "\t\t\t\t\t<ID>" << _id << "</ID>\n"
			<< "\t\t\t\t\t<ToolTip>" << _tooltip << "</ToolTip>\n"
			<< "\t\t\t\t\t<Default>" << _default << "</Default>\n"
			<< "\t\t\t\t</Literal>\n";

		return ss.str();
	}
#pragma endregion //} msvc_literal
#pragma  region msvc_snippet //{
	std::string
	msvc_snippet (
		const std::string& title,
		const std::string& description,
		const std::string& shortcut,
		const std::string& author,
		const str3vec& literals,
		const std::string& code
	) {
		#pragma region variables //{			
			std::stringstream ss;

		#pragma endregion //} variables

		ss << "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n"
			<< "<CodeSnippets  xmlns = \"http://schemas.microsoft.com/VisualStudio/2005/CodeSnippet\">\n"
			<< "\t<CodeSnippet Format=\"1.0.0\">\n"
			<< "\t\t<Header>\n"
			<< "\t\t\t<Title>" << title << "</Title>\n"
			<< "\t\t\t<Shortcut>" << shortcut << "</Shortcut>\n"
			<< "\t\t\t<Description>" << description << "</Description>\n"
			<< "\t\t\t<Author>" << author << "</Author>\n"
			<< "\t\t\t<SnippetTypes>\n"
			<< "\t\t\t\t<SnippetType>Expansion</SnippetType>\n"
			<< "\t\t\t\t<SnippetType>SurroundsWith</SnippetType>\n"
			<< "\t\t\t</SnippetTypes>\n"
			<< "\t\t</Header>\n"
			<< "\t\t<Snippet>\n"
			<< "\t\t\t<Declarations>\n";

		for (std::size_t it = 0; it < literals.size(); it++) {
			ss << msvc_literal(literals.at(it));
		}

		ss << "\t\t\t</Declarations>\n"
			<< "\t\t\t<Code Language = \"cpp\">\n"
			<< "\t\t\t\t<![CDATA[" << code << "]]>\n"
			<< "\t\t\t</Code>\n"
			<< "\t\t</Snippet>\n"
			<< "\t</CodeSnippet>\n"
			<< "</CodeSnippets>\n";

		return ss.str();
	}
#pragma endregion //} msvc_snippet
#pragma region msvc_write //{
	void
	msvc_write (
		std::string filepath,
		json snippet
	) {
		std::ofstream file;
		std::string str;

		std::string filename = snippet.begin().key();
		replace_all(filename, " ", "_");

		str = convert_to_msvc_snippet(snippet);
		//std::cout << msvc_str << std::endl;
		
		filepath += filename + ".snippet";
		file.open(filepath);
		if (file.is_open()) {
			//std::cout << "writting to snippet file...\n";
			file << str;
		} else {
			std::cout << "could not open " << filepath << "\n";
		}
		file.close();
	}
#pragma endregion //} msvc_write



#pragma region conversion_functions //{
	#pragma region convert_to_vscode_snippet //{
		std::string convert_to_vscode_snippet(
			const json& json_obj
		) {
			return json_obj.dump(true, '\t', true);
		}
	#pragma endregion //} convert_to_vscode_snippet
	#pragma region convert_to_msvc_snippet //{
		std::string convert_to_msvc_snippet (
			const json &json_obj
		) {
			#pragma region variables //{
				std::string result;

				json::const_iterator it;
				json snippet;
				json json_body;

				std::string title;
				std::string prefix;
				std::string description;
				std::string body = "";
				char chr;

				ullvec splaceholders;
				
				std::string line;
				std::string literal_name;
				std::string literal_json;
				std::string literal_msvc;

				str3vec literals;


			#pragma endregion //} variables

			title = json_obj.begin().key();
			snippet = *json_obj.begin();
				
			it = snippet.find("prefix");
			if (it == snippet.end()) {
				throw;
			}
			try {
				prefix = it.value();
			} catch (std::exception & ex) {
				std::cout << ex.what() << std::endl;
				throw ex;
			}
				
			it = snippet.find("description");
			if (it == snippet.end()) {
				throw;
			}
			try {
				description = it.value();
			} catch (std::exception & ex) {
				std::cout << ex.what() << std::endl;
				throw ex;
			}

			it = snippet.find("body");
			if (it == snippet.end()) {
				throw;
			}

			json_body = it.value();
				
			for (
				json::iterator body_it = json_body.begin();
				body_it != json_body.end();
				body_it++
			) {
				try {
					body += body_it.value();
					body += "\n";
				}
				catch (std::exception & ex) {
					std::cout << ex.what() << std::endl;
					throw ex;
				}
			}
			//std::cout << body << std::endl;


			for (std::size_t it = 0; it < body.size(); it++)
			{
				chr = body.at(it);
				if (chr == '$') {
					splaceholders.emplace_back(it);
				}
			}

			for (std::size_t it1 = 0; it1 < splaceholders.size(); it1++)
			{
				line.clear();
				for (std::size_t it2 = splaceholders.at(it1); it2 < body.size(); it2++)
				{
					chr = body.at(it2);
					line += chr;
					if (chr == '}' || chr == ' ') {
						break;
					}
						
				}
				literals.emplace_back(std::forward_as_tuple("", line, ""));
			}

			std::sort(literals.begin(), literals.end());
			literals.erase(
				std::unique(
					literals.begin(),
					literals.end()
				),
				literals.end()
			);

			for (std::size_t it1 = 0; it1 < literals.size(); it1++) {
				std::get<0>(literals.at(it1)) = std::string(
					std::get<1>(literals.at(it1)).begin() + 2,
					std::get<1>(literals.at(it1)).end() - 1
				);
				std::get<2>(literals.at(it1)) = "$" + std::get<0>(literals.at(it1)) + "$";
			}

			//for (std::size_t it1 = 0; it1 < msvc_literals.size(); it1++) {
			//	std::cout << msvc_literals.at(it1) << std::endl;
			//}
			//std::cout << std::endl;

			literals.erase (
				std::remove_if (
					literals.begin(),
					literals.end(),
					[](const str3 &_str3) -> bool {
						return (std::get<0>(_str3) == "0");
					}
				),
				literals.end()
			);

			for (std::size_t it1 = 0, it3 = 0; it1 < literals.size(); it1++) {
				std::tie(literal_name, literal_json, literal_msvc) = literals.at(it1);
				replace_all(body, literal_json, literal_msvc);
			}

			replace_all(body, "${0}", "$selected$$end$");
			//std::cout << body << std::endl;

			for (std::size_t it1 = 0; it1 < literals.size(); it1++) {
				std::get<1>(literals.at(it1)) = std::get<0>(literals.at(it1));
				std::get<2>(literals.at(it1)) = std::get<0>(literals.at(it1));
			}

			result = msvc_snippet (
				title,
				description,
				prefix,
				"Luis Vega",
				literals,
				body
			);
			
			//std::cout << result;
				

			return result;
		}
	#pragma endregion //} convert_to_msvc_snippet
#pragma endregion //} conversion_functions

#pragma region snippets //{
	#pragma region simple //{
		#pragma region region_snippet //{
			std::string snippet::region_str (
				std::string region_name = "${region_name}",
				std::string body = "${0}"
			)
			{
				std::stringstream ss;

				ss	<< "#pragma region " << region_name << " //{\n"
					<< "\t" << replace_all(body, "\n", "\n\t") << "\n"
					<< "#pragma endregion //} " << region_name << "\n";

				return ss.str();
			}
			json snippet::region ()
			{
				#pragma region variables //{
					json result;
					std::string body;

				#pragma endregion //} variables

				body = region_str();

				result = json_snippet (
					"region block",		// title
					"rg",				// prefix/shortcut
					body,				// body
					"region block"		// description
				);

				return result;
			}
		#pragma endregion //} region_snippet
		#pragma region function_snippet //{
			std::string snippet::function_str (
				std::string return_type = "${return_type}",
				std::string function_name = "${function_name}",
				std::string arguments = "",
				std::string body = "${0}"
			) {
				std::stringstream ss;
				ss	<< return_type << " " << function_name << " (" << arguments << ")\n"
					<< "{\n"
					<< "\t" << replace_all(body, "\n", "\n\t") << "\n"
					<< "}\n";

				return ss.str();
			}
			std::string snippet::p_function_str (
				std::string return_type = "${return_type}",
				std::string function_name = "${function_name}",
				std::string arguments = "",
				std::string body = "${0}"
			) {
				std::stringstream ss;

				ss << region_str(
					function_name,
					function_str(
						return_type,
						function_name,
						arguments,
						body
					)
				);

				return ss.str();
			}
			std::string snippet::function_body_str (
				std::string return_type = "${return_type}",
				std::string body = "${0}"
			) {
				std::stringstream ss;

				ss << region_str("variables", return_type + " result;")
					<< "\n"
					<< "//TODO:\n"
					<< body << "\n\n"
					<< "return result;";

				return ss.str();
			}
			std::string snippet::pb_function_str (
				std::string return_type = "${return_type}",
				std::string function_name = "${function_name}",
				std::string arguments = "",
				std::string body = "${0}"
			)
			{
				std::stringstream ss;

				//TODO:
				ss << p_function_str (
					return_type,
					function_name,
					arguments,
					function_body_str(return_type, body)
				);

				return ss.str();
			}

			json snippet::basic_function()
			{
				#pragma region variables //{
					json result;
					std::string body;

				#pragma endregion //} variables

				body = function_str();

				result = json_snippet (
					"basic function",	// title
					"bfn",				// prefix/shortcut
					body,				// body
					"basic function"	// description
				);

				return result;
			}
			json snippet::snippet_function() {
				#pragma region variables //{
					json result;
					std::string body;
					std::stringstream ss1, ss2;

				#pragma endregion //} variables

				ss1 << "std::stringstream ss;\n"
					<< "//TODO:\n"
					<< "${0}\n\n"
					<< "return ss.str();";

				ss2	<< "#pragma region variables //{\n"
					<< "\t\tjson result;\n"
					<< "\t\tstd::string body;\n"
					<< "\t\n"
					<< "\t#pragma endregion //} variables\n"
					<< "\t\n"
					<< "\tbody = ${function_name}_str();\n"
					<< "\t\n"
					<< "\tresult = json_snippet (\n"
					<< "\t\t\"snippet function\",\t\t// title\n"
					<< "\t\t\"snip\",\t\t\t\t\t// prefix/shortcut\n"
					<< "\t\tbody,\t\t\t\t\t// body\n"
					<< "\t\t\"snippet function\"\t\t// description\n"
					<< "\t);\n"
					<< "\t\n"
					<< "\treturn result;";

				body = function_str(
					"std::string",
					"snippet::${function_name}_str",\
					"",
					ss1.str()
				);
				body += "\n";
				body += function_str (
					"json",
					"snippet::${function_name}",
					"",
					ss2.str()
				);

				result = json_snippet (
					"snippet function",	// title
					"snip",				// prefix/shortcut
					body,				// body
					"snippet function"	// description
				);

				return result;

				
			}
			json snippet::p_function()
			{
				#pragma region variables //{
					json result;
					std::string body;

				#pragma endregion //} variables

				body = p_function_str();

				result = json_snippet(
					"pragma function",		// title
					"pfn",					// prefix/shortcut
					body,					// body
					"pragma function"		// description
				);

				return result;

			}
			json snippet::function_body()
			{
				#pragma region variables //{
					json result;
					std::string body;

				#pragma endregion //} variables

				body = function_body_str();

				result = json_snippet(
					"function body",		// title
					"fnb",					// prefix/shortcut
					body,					// body
					"function body"		// description
				);

				return result;
			}
			json snippet::pb_function()
			{
				#pragma region variables //{
					json result;
					std::string body;

				#pragma endregion //} variables

				body = pb_function_str();

				result = json_snippet(
					"pb function",		// title
					"fn",					// prefix/shortcut
					body,					// body
					"pb function"		// description
				);

				return result;
			}
			


		#pragma endregion //} function_snippet

			
	#pragma endregion //} simple
	#pragma region function_snippets //{
		#pragma region non-templated //{
			#pragma region generate_nscfn_nth_snippet //{
				json
				generate_nscfn_nth_snippet (
					const std::string &title,
					const std::string &prefix,
					const std::vector<std::string> &params,
					const std::size_t &argc
				)
				{
					#pragma region variables //{
						json results;
						std::vector<std::pair<std::string, std::string>> argv(argc);
					#pragma endregion //} variables


					for (std::size_t it = 0; it < argc; it++) {
						argv.at(it).first = "int";
						argv.at(it).second = "arg" + std::to_string(it + 1);

						//std::cout << argv.at(it).second << std::endl;
					}

					if (argc == 0) {
						results = generate_nscfn_nth_snippet(title, prefix, params, argv);
					} else {
						results = generate_nscfn_nth_snippet(title, prefix + std::to_string(argc), params, argv);
					}

					return results;
				}

				json
				generate_nscfn_nth_snippet (
					const std::string &title,
					const std::string &prefix,
					const std::vector<std::string> &params,
					const std::vector<std::pair<std::string, std::string>> &argv
				)
				{
					#pragma region variables //{
						json results;
						std::string _title;
						int n_args = argv.size();

						std::vector<std::string> body_strs;
						std::vector<std::string> decl_strs;
					#pragma endregion //} variables

					//TODO:
					_title = (argv.size() >= 1) ? title + " " + std::to_string(argv.size()) : title;
					results[_title]["prefix"] = prefix;

					body_strs.emplace_back("#pragma region ${1:" + params.at(0) + "} //{");
					body_strs.emplace_back("\t// Implementation");
					body_strs.emplace_back("\t${2:" + params.at(1) + "}");

					if (n_args == 0) {
						results[_title]["description"] = title + " with no arguments";

						body_strs.emplace_back("\t${3:" + params.at(2) + "}::${4:" + params.at(3) + "}::${1} () ${5:" + params.at(4) + "}");
					}
					else if (n_args == 1) {
						results[_title]["description"] = title + " with 1 argument";

						body_strs.emplace_back("\t${3:" + params.at(2) + "}::${4:" + params.at(3) + "}::${1} (");
						body_strs.emplace_back("\t\t${5:" + argv.at(0).first + "} ${6:" + argv.at(0).second + "}");
						body_strs.emplace_back("\t) ${6:" + params.at(4) + "}");
					}
					else {
						results[_title]["description"] = title + " with " + std::to_string(n_args) + " arguments";

						body_strs.emplace_back("\t${3:" + params.at(2) + "}::${4:" + params.at(3) + "}::${1} (");
						for (std::size_t it = 0; it < argv.size(); it++) {
							body_strs.emplace_back("\t\t${" + std::to_string(5 + 2*it) + ":" + argv.at(it).first + "} ${" + std::to_string(6 + 2*it) + ":" + argv.at(it).second + "}, ");
						}
						body_strs.emplace_back("\t) ${" + std::to_string(5 + 2*argv.size()) + ":" + params.at(4) + "}");
					}
		
					decl_strs.emplace_back("#pragma region ${1:" + params.at(0) + "} //{");
					decl_strs.emplace_back("\t// Declaration");
					decl_strs.emplace_back("\t${2:" + params.at(1) + "}");
					if (n_args == 0) {
						decl_strs.emplace_back("\t${1} () ${5:" + params.at(4) + "};");
					} else {
						decl_strs.emplace_back("\t${1} (");
						decl_strs.insert(decl_strs.end(), body_strs.begin() + 4, body_strs.end() - 1);
						decl_strs.emplace_back("\t) ${" + std::to_string(5 + 2 * argv.size()) + ":" + params.at(4) + "};");
					}
		
					decl_strs.emplace_back("#pragma endregion //} ${1}");
					decl_strs.emplace_back("");

					body_strs.emplace_back("\t{");
					body_strs.emplace_back("\t\t#pragma region variables //{");
					body_strs.emplace_back("\t\t\t${2} result;");
					body_strs.emplace_back("\t\t\t");
					body_strs.emplace_back("\t\t#pragma endregion //} variables");
					body_strs.emplace_back("\t\t");
					body_strs.emplace_back("\t\t//TODO:");
					body_strs.emplace_back("\t\t${" + std::to_string(params.size() + 2 * argv.size() + 1) + "}");
					body_strs.emplace_back("\t\t");
					body_strs.emplace_back("\t\treturn result;");
					body_strs.emplace_back("\t}");
					body_strs.emplace_back("#pragma endregion //} ${1}");
					body_strs.emplace_back("");

					body_strs.insert(body_strs.begin(), decl_strs.begin(), decl_strs.end());

					results[_title]["body"] = json(body_strs);

					return results;
				}
			#pragma endregion //} generate_nscfn_nth_snippet
			#pragma region generate_nscfn_snippets //{
				json
					generate_nscfn_snippets(
						const std::string& title,
						const std::string& prefix,
						const std::vector<std::string>& params,
						const std::size_t& argc
					)
				{
					#pragma region variables //{
						json results;
						json json_obj;
					#pragma endregion //} variables

					//TODO:
					for (std::size_t it = 0; it < argc; it++) {
						json_obj = generate_nscfn_nth_snippet(title, prefix, params, it);
						results = json_append(results, json_obj);
					}
					return results;
				}
			#pragma endregion //} generate_nscfn_snippets

			#pragma region generate_cfn_nth_snippet //{
				json
				generate_cfn_nth_snippet(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				)
				{
					#pragma region variables //{
						json results;
						std::vector<std::pair<std::string, std::string>> argv(argc);
					#pragma endregion //} variables


					for (std::size_t it = 0; it < argc; it++) {
						argv.at(it).first = "int";
						argv.at(it).second = "arg" + std::to_string(it + 1);
					}

					if (argc == 0) {
						results = generate_cfn_nth_snippet(title, prefix, params, argv);
					}
					else {
						results = generate_cfn_nth_snippet(title, prefix + std::to_string(argc), params, argv);
					}

					return results;
				}
				json
				generate_cfn_nth_snippet(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::vector<std::pair<std::string, std::string>>& argv
				)
				{
					#pragma region variables //{
						json results;
						std::string _title;
						int n_args = argv.size();

						std::vector<std::string> decl_strs;
						std::vector<std::string> body_strs;
					#pragma endregion //} variables

					//TODO:
					_title = (argv.size() >= 1) ? title + " " + std::to_string(argv.size()) : title;
					results[_title]["prefix"] = prefix;

					body_strs.emplace_back("#pragma region ${1:" + params.at(0) + "} //{");
					body_strs.emplace_back("\t// Implementation");
					body_strs.emplace_back("\t${2:" + params.at(1) + "}");

					if (n_args == 0) {
						results[_title]["description"] = title + " with no arguments";

						body_strs.emplace_back("\t${3:" + params.at(2) + "}::${1} () ${4:" + params.at(3) + "}");
					}
					else if (n_args == 1) {
						results[_title]["description"] = title + " with 1 argument";

						body_strs.emplace_back("\t${3:" + params.at(2) + "}::${1} (");
						body_strs.emplace_back("\t\t${4:" + argv.at(0).first + "} ${5:" + argv.at(0).second + "}");
						body_strs.emplace_back("\t) ${6:" + params.at(3) + "}");
					}
					else {
						results[_title]["description"] = title + " with " + std::to_string(n_args) + " arguments";

						body_strs.emplace_back("\t${3:" + params.at(2) + "}::${1} (");
						for (std::size_t it = 0; it < argv.size(); it++) {
							body_strs.emplace_back("\t\t${" + std::to_string(4 + 2*it) + ":" + argv.at(it).first + "} ${" + std::to_string(5 + 2*it) + ":" + argv.at(it).second + "}, ");
						}
						body_strs.emplace_back("\t) ${" + std::to_string(4 + 2*argv.size()) + ":" + params.at(3) + "}");
					}

					decl_strs.emplace_back("#pragma region ${1:" + params.at(0) + "} //{");
					decl_strs.emplace_back("\t// Declaration");
					decl_strs.emplace_back("\t${2:" + params.at(1) + "}");
					if (n_args == 0) {
						decl_strs.emplace_back("\t${1} () ${4:" + params.at(3) + "};");
					}
					else {
						decl_strs.emplace_back("\t${1} (");
						decl_strs.insert(decl_strs.end(), body_strs.begin() + 4, body_strs.end() - 1);
						decl_strs.emplace_back("\t) ${" + std::to_string(4 + 2 * argv.size()) + ":" + params.at(3) + "};");
					}

					decl_strs.emplace_back("#pragma endregion //} ${1}");
					decl_strs.emplace_back("");

					body_strs.emplace_back("\t{");
					body_strs.emplace_back("\t\t#pragma region variables //{");
					body_strs.emplace_back("\t\t\t${2} result;");
					body_strs.emplace_back("\t\t\t");
					body_strs.emplace_back("\t\t#pragma endregion //} variables");
					body_strs.emplace_back("\t\t");
					body_strs.emplace_back("\t\t//TODO:");
					body_strs.emplace_back("\t\t${" + std::to_string(params.size() + 2 * argv.size() + 1) + "}");
					body_strs.emplace_back("\t\t");
					body_strs.emplace_back("\t\treturn result;");
					body_strs.emplace_back("\t}");
					body_strs.emplace_back("#pragma endregion //} ${1}");
					body_strs.emplace_back("");

					body_strs.insert(body_strs.begin(), decl_strs.begin(), decl_strs.end());

					results[_title]["body"] = json(body_strs);

					return results;
				}
			#pragma endregion //} generate_cfn_nth_snippet
			#pragma region generate_cfn_snippets //{
				json
				generate_cfn_snippets(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				)
				{
					#pragma region variables //{
						json results;
						json json_obj;
					#pragma endregion //} variables

					//TODO:
					for (std::size_t it = 0; it < argc; it++) {
						json_obj = generate_cfn_nth_snippet(title, prefix, params, it);
						results = json_append(results, json_obj);
					}
					return results;
				}
			#pragma endregion //} generate_cfn_snippets

			#pragma region generate_nsfn_nth_snippet //{
				json
				generate_nsfn_nth_snippet(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				)
				{
					#pragma region variables //{
						json results;
						std::vector<std::pair<std::string, std::string>> argv(argc);
					#pragma endregion //} variables


					for (std::size_t it = 0; it < argc; it++) {
						argv.at(it).first = "int";
						argv.at(it).second = "arg" + std::to_string(it + 1);

						//std::cout << argv.at(it).second << std::endl;
					}

					if (argc == 0) {
						results = generate_nsfn_nth_snippet(title, prefix, params, argv);
					}
					else {
						results = generate_nsfn_nth_snippet(title, prefix + std::to_string(argc), params, argv);
					}

					return results;
				}
				json
				generate_nsfn_nth_snippet(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::vector<std::pair<std::string, std::string>>& argv
				)
				{
					#pragma region variables //{
						json results;
						std::string _title;
						int n_args = argv.size();

						std::vector<std::string> decl_strs;
						std::vector<std::string> body_strs;
					#pragma endregion //} variables

					//TODO:
					_title = (argv.size() >= 1) ? title + " " + std::to_string(argv.size()) : title;
					results[_title]["prefix"] = prefix;

					body_strs.emplace_back("#pragma region ${1:" + params.at(0) + "} //{");
					body_strs.emplace_back("\t// Implementation");
					body_strs.emplace_back("\t${2:" + params.at(1) + "}");

					if (n_args == 0) {
						results[_title]["description"] = title + " with no arguments";

						body_strs.emplace_back("\t${3:" + params.at(2) + "}::${1} ()");
					}
					else if (n_args == 1) {
						results[_title]["description"] = title + " with 1 argument";

						body_strs.emplace_back("\t${3:" + params.at(2) + "}::${1} (");
						body_strs.emplace_back("\t\t${5:" + argv.at(0).first + "} ${6:" + argv.at(0).second + "}");
						body_strs.emplace_back("\t)");
					}
					else {
						results[_title]["description"] = title + " with " + std::to_string(n_args) + " arguments";

						body_strs.emplace_back("\t${3:" + params.at(2) + "}::${1} (");
						for (std::size_t it = 0; it < argv.size(); it++) {
							body_strs.emplace_back("\t\t${" + std::to_string(5 + 2 * it) + ":" + argv.at(it).first + "} ${" + std::to_string(6 + 2 * it) + ":" + argv.at(it).second + "}, ");
						}
						body_strs.emplace_back("\t)");
					}

					decl_strs.emplace_back("#pragma region ${1:" + params.at(0) + "} //{");
					decl_strs.emplace_back("\t// Declaration");
					decl_strs.emplace_back("\t${2:" + params.at(1) + "}");
					if (n_args == 0) {
						decl_strs.emplace_back("\t${1} ();");
					}
					else {
						decl_strs.emplace_back("\t${1} (");
						decl_strs.insert(decl_strs.end(), body_strs.begin() + 4, body_strs.end() - 1);
						decl_strs.emplace_back("\t);");
					}

					decl_strs.emplace_back("#pragma endregion //} ${1}");
					decl_strs.emplace_back("");

					body_strs.emplace_back("\t{");
					body_strs.emplace_back("\t\t#pragma region variables //{");
					body_strs.emplace_back("\t\t\t${2} result;");
					body_strs.emplace_back("\t\t\t");
					body_strs.emplace_back("\t\t#pragma endregion //} variables");
					body_strs.emplace_back("\t\t");
					body_strs.emplace_back("\t\t//TODO:");
					body_strs.emplace_back("\t\t${" + std::to_string(params.size() + 2 * argv.size() + 1) + "}");
					body_strs.emplace_back("\t\t");
					body_strs.emplace_back("\t\treturn result;");
					body_strs.emplace_back("\t}");
					body_strs.emplace_back("#pragma endregion //} ${1}");
					body_strs.emplace_back("");

					body_strs.insert(body_strs.begin(), decl_strs.begin(), decl_strs.end());

					results[_title]["body"] = json(body_strs);

					return results;
				}
			#pragma endregion //} generate_nsfn_nth_snippet
			#pragma region generate_nsfn_snippets //{
				json
				generate_nsfn_snippets(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				)
				{
					#pragma region variables //{
						json results;
						json json_obj;
					#pragma endregion //} variables

					//TODO:
					for (std::size_t it = 0; it < argc; it++) {
						json_obj = generate_nsfn_nth_snippet(title, prefix, params, it);
						results = json_append(results, json_obj);
					}
					return results;
				}
			#pragma endregion //} generate_nsfn_snippets

			#pragma region generate_fn_nth_snippet //{
				json
				generate_fn_nth_snippet (
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				)
				{
					#pragma region variables //{
						json results;
						std::vector<std::pair<std::string, std::string>> argv(argc);
					#pragma endregion //} variables


					for (std::size_t it = 0; it < argc; it++) {
						argv.at(it).first = "int";
						argv.at(it).second = "arg" + std::to_string(it + 1);
					}

					if (argc == 0) {
						results = generate_fn_nth_snippet(title, prefix, params, argv);
					}
					else {
						results = generate_fn_nth_snippet(title, prefix + std::to_string(argc), params, argv);
					}

					return results;
				}
				json
				generate_fn_nth_snippet (
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::vector<std::pair<std::string, std::string>>& argv
				)
				{
					#pragma region variables //{
						json results;
						std::string _title;
						int n_args = argv.size();

						std::vector<std::string> decl_strs;
						std::vector<std::string> body_strs;
					#pragma endregion //} variables

					//TODO:
					_title = (argv.size() >= 1) ? title + " " + std::to_string(argv.size()) : title;
					results[_title]["prefix"] = prefix;

					body_strs.emplace_back("#pragma region ${1:" + params.at(0) + "} //{");
					body_strs.emplace_back("\t// Implementation");
					body_strs.emplace_back("\t${2:" + params.at(1) + "}");

					if (n_args == 0) {
						results[_title]["description"] = title + " with no arguments";

						body_strs.emplace_back("\t${1} ()");
					}
					else if (n_args == 1) {
						results[_title]["description"] = title + " with 1 argument";

						body_strs.emplace_back("\t${1} (");
						body_strs.emplace_back("\t\t${3:" + argv.at(0).first + "} ${4:" + argv.at(0).second + "}");
						body_strs.emplace_back("\t)");
					}
					else {
						results[_title]["description"] = title + " with " + std::to_string(n_args) + " arguments";

						body_strs.emplace_back("\t${1} (");
						for (std::size_t it = 0; it < argv.size(); it++) {
							body_strs.emplace_back("\t\t${" + std::to_string(3 + 2 * it) + ":" + argv.at(it).first + "} ${" + std::to_string(4 + 2 * it) + ":" + argv.at(it).second + "}, ");
						}
						body_strs.emplace_back("\t)");
					}

					decl_strs.emplace_back("#pragma region ${1:" + params.at(0) + "} //{");
					decl_strs.emplace_back("\t// Declaration");
					decl_strs.emplace_back("\t${2:" + params.at(1) + "}");
					if (n_args == 0) {
						decl_strs.emplace_back("\t${1} ();");
					}
					else {
						decl_strs.emplace_back("\t${1} (");
						decl_strs.insert(decl_strs.end(), body_strs.begin() + 4, body_strs.end() - 1);
						decl_strs.emplace_back("\t);");
					}

					decl_strs.emplace_back("#pragma endregion //} ${1}");
					decl_strs.emplace_back("");

					body_strs.emplace_back("\t{");
					body_strs.emplace_back("\t\t#pragma region variables //{");
					body_strs.emplace_back("\t\t\t${2} result;");
					body_strs.emplace_back("\t\t\t");
					body_strs.emplace_back("\t\t#pragma endregion //} variables");
					body_strs.emplace_back("\t\t");
					body_strs.emplace_back("\t\t//TODO:");
					body_strs.emplace_back("\t\t${" + std::to_string(params.size() + 2 * argv.size() + 1) + "}");
					body_strs.emplace_back("\t\t");
					body_strs.emplace_back("\t\treturn result;");
					body_strs.emplace_back("\t}");
					body_strs.emplace_back("#pragma endregion //} ${1}");
					body_strs.emplace_back("");

					body_strs.insert(body_strs.begin(), decl_strs.begin(), decl_strs.end());

					results[_title]["body"] = json(body_strs);

					return results;
				}
			#pragma endregion //} generate_fn_nth_snippet
			#pragma region generate_fn_snippets //{
				json
				generate_fn_snippets(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::string>& params,
					const std::size_t& argc
				)
				{
					#pragma region variables //{
						json results;
						json json_obj;
					#pragma endregion //} variables

					//TODO:
					for (std::size_t it = 0; it < argc; it++) {
						json_obj = generate_fn_nth_snippet(title, prefix, params, it);
						results = json_append(results, json_obj);
					}
					return results;
				}
			#pragma endregion //} generate_fn_snippets
		#pragma endregion //} non-templated
		#pragma region templated //{
			#pragma region generate_tnscfn_nth_snippet //{
				json
				generate_tnscfn_nth_snippet(
					const std::string& title,
					const std::string& prefix,
					const std::size_t& argc
				)
				{
					#pragma region variables //{
						json results;
						std::vector<std::pair<std::string, std::string>> argv(argc);
					#pragma endregion //} variables


					for (std::size_t it = 0; it < argc; it++) {
						argv.at(it).first = "int";
						argv.at(it).second = "arg" + std::to_string(it + 1);

						//std::cout << argv.at(it).second << std::endl;
					}

					if (argc == 0) {
						results = generate_tnscfn_nth_snippet(title, prefix, argv);
					}
					else {
						results = generate_tnscfn_nth_snippet(title, prefix + std::to_string(argc), argv);
					}

					return results;
				}
				json
				generate_tnscfn_nth_snippet(
					const std::string& title,
					const std::string& prefix,
					const std::vector<std::pair<std::string, std::string>>& argv
				)
				{
					#pragma region variables //{
						json results;
						std::string _title;
						int n_args = argv.size();

						std::vector<std::string> body_strs;
					#pragma endregion //} variables

					//TODO:
					_title = (argv.size() >= 1) ? title + " " + std::to_string(argv.size()) : title;
					results[_title]["prefix"] = prefix;

					body_strs.emplace_back("#pragma region ${1:function_name} //{");
					body_strs.emplace_back("\t// Implementation");
					body_strs.emplace_back("\t${2:int}");
					body_strs.emplace_back("\t${3:namespace_name}::${4:class_name}::${1} (${5:arguments}) ${6:const}");
					body_strs.emplace_back("\t{");
					body_strs.emplace_back("\t\t#pragma region variables //{");
					body_strs.emplace_back("\t\t\t${2} result;");
					body_strs.emplace_back("\t\t\t");
					body_strs.emplace_back("\t\t#pragma endregion //} variables");
					body_strs.emplace_back("\t\t");
					body_strs.emplace_back("\t\t//TODO:");
					body_strs.emplace_back("\t\t${0}");
					body_strs.emplace_back("\t\t");
					body_strs.emplace_back("\t\treturn result;");
					body_strs.emplace_back("\t}");
					body_strs.emplace_back("#pragma endregion //} ${1}");
					body_strs.emplace_back("");

					results[_title]["body"] = json(body_strs);
					results[_title]["description"] = title + " with no arguments";

					return results;
				}
			#pragma endregion //} generate_tnscfn_nth_snippet
			#pragma region generate_tnscfn_snippets //{
				json
				generate_tnscfn_snippets(
					const std::string& title,
					const std::string& prefix,
					const std::size_t& argc
				)
				{
					#pragma region variables //{
						json results;
						json json_obj;
					#pragma endregion //} variables

					//TODO:
					for (std::size_t it = 0; it < argc; it++) {
						json_obj = generate_tnscfn_nth_snippet(title, prefix, it);
						results = json_append(results, json_obj);
					}
					return results;
				}
			#pragma endregion //} generate_tnscfn_snippets
		#pragma endregion //} templated
	#pragma endregion //} function_snippets
#pragma endregion //} snippets

void snippet::generate(json snippet) {
	std::string vscode_path = "C:\\Users\\lvega\\AppData\\Roaming\\Code\\User\\snippets\\";
	std::string msvc_path = "C:\\Users\\lvega\\Documents\\Visual Studio 2019\\Code Snippets\\Visual C++\\My Code Snippets\\";

	vscode_write(vscode_path, snippet);
	msvc_write(msvc_path, snippet);
}


int main(int argc, char *argv[]) {
	#pragma region variables //{
		json json_doc;
		json json_obj;
		json snippet;

		std::string vscode_str;
		std::string msvc_str;

		std::size_t num_snippets_per_type = 10;
		std::vector<std::string> snippet_params;

	#pragma endregion //} variables

	//#pragma region nscfn_snippets //{
	//	snippet_params.clear();
	//	snippet_params.emplace_back("function_name");
	//	snippet_params.emplace_back("int");
	//	snippet_params.emplace_back("namespace_name");
	//	snippet_params.emplace_back("class_name");
	//	snippet_params.emplace_back("const");
	//
	//	json_obj = generate_nscfn_snippets(
	//		"Namespace-class function",
	//		"nscfn",
	//		snippet_params,
	//		num_snippets_per_type
	//	);
	//	json_doc = json_append(json_doc, json_obj);
	//#pragma endregion //} nscfn_snippets
	//#pragma region cfn_snippets //{
	//	snippet_params.clear();
	//	snippet_params.emplace_back("function_name");
	//	snippet_params.emplace_back("int");
	//	snippet_params.emplace_back("class_name");
	//	snippet_params.emplace_back("const");
	//
	//	json_obj = generate_cfn_snippets(
	//		"Class function",
	//		"cfn",
	//		snippet_params,
	//		num_snippets_per_type
	//	);
	//	json_doc = json_append(json_doc, json_obj);
	//#pragma endregion //} cfn_snippets
	//#pragma region nsfn_snippets //{
	//	snippet_params.clear();
	//	snippet_params.emplace_back("function_name");
	//	snippet_params.emplace_back("int");
	//	snippet_params.emplace_back("namespace_name");
	//	snippet_params.emplace_back("const");
	//
	//	json_obj = generate_nsfn_snippets (
	//		"Namespace function",
	//		"nsfn",
	//		snippet_params,
	//		num_snippets_per_type
	//	);
	//	json_doc = json_append(json_doc, json_obj);
	//#pragma endregion //} nsfn_snippets
	//#pragma region fn_snippets //{
	//	snippet_params.clear();
	//	snippet_params.emplace_back("function_name");
	//	snippet_params.emplace_back("int");
	//
	//	json_obj = generate_fn_snippets (
	//		"Function",
	//		"fn",
	//		snippet_params,
	//		num_snippets_per_type
	//	);
	//	json_doc = json_append(json_doc, json_obj);
	//#pragma endregion //} fn_snippets

	//#pragma region tnscfn_snippets //{
	//	json_obj = generate_tnscfn_snippets (
	//		"Templated function",
	//		"nsctfn",
	//		1
	//	);
	//	json_doc = json_append(json_doc, json_obj);
	//#pragma endregion //} tnscfn_snippets

	snippet::generate(snippet::region());
	snippet::generate(snippet::basic_function());
	snippet::generate(snippet::function_body());
	snippet::generate(snippet::snippet_function());
	snippet::generate(snippet::p_function());
	snippet::generate(snippet::pb_function());



	

	// example
	//std::cout << msvc_snippet (
	//	"title",
	//	"description",
	//	"shortcut",
	//	"author",
	//	{ { {"id1","tooltip1","default1"}, {"id2","tooltip2","default2"} } },
	//	"code"
	//) << std::endl;
	//
	// example
	//std::cout << vscode_snippet (
	//	"title",
	//	"prefix",
	//	{ {"code"} },
	//	"description"
	//) << std::endl;

	std::cout << "End of program. (press any key to continue... )";
	std::cin.get();
	return 0;
}

template <class T1>
int function_name() {
	int result;

	return result;
}