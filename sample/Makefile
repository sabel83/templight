# Copyright (C) 2013, Abel Sinkovics (abel@sinkovics.hu)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

BIN=..

all : generate

instantiated_templates.txt : fib.xml ; $(BIN)/instantiated_templates $< > $@
OUT+=instantiated_templates.txt

instantiation_diagram.dot : fib.xml ; $(BIN)/instantiation_diagram $< > $@
OUT+=instantiation_diagram.dot

instantiation_diagram.svg : instantiation_diagram.dot ; dot -Tsvg $< -o $@
OUT+=instantiation_diagram.svg

instantiation_diagram.png : instantiation_diagram.dot ; dot -Tpng $< -o $@
OUT+=instantiation_diagram.png

generate : $(OUT)

clean : ; -rm $(OUT)

