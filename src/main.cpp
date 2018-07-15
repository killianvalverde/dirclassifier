/* dirclassifier
 * Copyright (C) 2018-2023 Killian Valverde.
 *
 * This file is part of dirclassifier.
 *
 * dirclassifier is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dirclassifier is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dirclassifier. If not, see <http://www.gnu.org/licenses/>.
 */

#include <speed/speed.hpp>
#include <speed/speed_alias.hpp>

#include "program.hpp"


int main(int argc, char* argv[])
{
    spd::ap::arg_parser ap("dirclassifier");
    ap.add_help_text("Create a directory tree that represents entries in which symbolic "
                     "links are used to point to other directories and thus classify them. "
                     "JSON files are used to specify the entries in the source directories.\n");
    ap.add_key_value_arg({"--categories-files", "-cf"},
                         "Categories files names. The default value is '.categories.json'.",
                         {spd::ap::avt_t::STRING}, 1u, ~0u);
    ap.add_help_arg({"--help"}, "Display this help and exit.");
    ap.add_gplv3_version_arg({"--version"}, "Output version information and exit", "1.0.0", "2023",
                             "Killian Valverde");
    ap.add_keyless_arg("SOURCE-DIR", "Source directory", "", {spd::ap::avt_t::RWX_DIR});
    ap.add_keyless_arg("DESTINATION-DIR", "Destination directory", "", {spd::ap::avt_t::RWXC_DIR});
    ap.add_help_text("");
    ap.add_help_text("Example:\n"
                     "$ classifier ./Index ./Categories");
    ap.add_help_text("");
    ap.add_help_text("Example of JSON file:\n"
                     "{\n"
                     "    \"Published\": \"2013\",\n"
                     "    \"Genres\": [\"Drama\", \"Shoujo\"],\n"
                     "    \"Authors\": \"Keiko Suenobu\",\n"
                     "    \"Serialization\": \"Bessatsu Friend\",\n"
                     "    \"Mark\": 9,\n"
                     "    \"Languages\": [\"French\", \"English\"],\n"
                     "    \"Status\": \"Completed\"\n"
                     "}");
    ap.parse_args((unsigned int)argc, argv);
    
    dirclassifier::program prog(
            ap.get_front_arg_value_as<std::filesystem::path>("SOURCE-DIR"),
            ap.get_front_arg_value_as<std::filesystem::path>("DESTINATION-DIR"),
            ap.get_arg_values_as<std::string>("--categories-files", {".categories.json"}));
    
    return prog.execute();
}
